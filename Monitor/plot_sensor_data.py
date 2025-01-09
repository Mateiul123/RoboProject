import serial
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import re  

SERIAL_PORT = 'COM6'  
BAUD_RATE = 115200
ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)

ecg_data = []


WINDOW_SIZE = 200  

def read_serial_data():
    """Reads and extracts numeric heart rate data from the ESP32"""
    try:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').strip()
            print(f"Raw data: {line}") # Print the raw data for debugging
            match = re.search(r"Heart Rate: ([\d.]+)", line)  # Extract numeric value
            if match:
                return float(match.group(1))  
            else:
                print("Non-matching data. Skipping...")
    except Exception as e:
        print(f"Error reading data: {e}")
    return None

def update_plot(frame):
    """Updates the plot with new ECG data"""
    value = read_serial_data()
    if value is not None:
        ecg_data.append(value)
        
        # Limit the data to the last WINDOW_SIZE points
        if len(ecg_data) > WINDOW_SIZE:
            ecg_data.pop(0)

        # Update the plot line
        line.set_ydata(ecg_data)
        line.set_xdata(range(len(ecg_data)))
        ax.relim()
        ax.autoscale_view()

    return line,

# plot setup
fig, ax = plt.subplots()
line, = ax.plot([], [], lw=2)
ax.set_xlim(0, WINDOW_SIZE)
ax.set_ylim(0, 200)  
ax.set_title("Real-Time Heart Rate")
ax.set_xlabel("Sample Points")
ax.set_ylabel("Heart Rate (BPM)")

# Start the animation
ani = FuncAnimation(fig, update_plot, interval=1)  # Update every 10ms

plt.tight_layout()
plt.show()
