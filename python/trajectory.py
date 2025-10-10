import sys
import pandas as pd
import matplotlib.pyplot as plt
import os

# -------------------------------
script_dir = os.path.dirname(os.path.abspath(__file__))
csv_folder = os.path.join(script_dir, "../output/csv")
# -------------------------------

def visualize(rocket_name):
    # Read CSV
    filename = os.path.join(csv_folder, f"{rocket_name}.csv")
    data = pd.read_csv(filename)

    # Plot Altitude vs Time
    plt.figure(figsize=(10,6))
    plt.plot(data['time'], data['altitude'], label='Altitude (m)', color='blue')
    plt.xlabel('Time (s)')
    plt.ylabel('Altitude (m)')
    plt.title(f'{rocket_name} - Altitude vs Time')
    plt.grid(True)
    plt.legend()
    plt.tight_layout()
    plt.show()

    # Plot Velocity vs Time
    plt.figure(figsize=(10,6))
    plt.plot(data['time'], data['velocity'], label='Velocity (m/s)', color='green')
    plt.xlabel('Time (s)')
    plt.ylabel('Velocity (m/s)')
    plt.title(f'{rocket_name} - Velocity vs Time')
    plt.grid(True)
    plt.legend()
    plt.tight_layout()
    plt.show()

    # Plot Acceleration vs Time
    plt.figure(figsize=(10,6))
    plt.plot(data['time'], data['acceleration'], label='Acceleration (m/s²)', color='red')
    plt.xlabel('Time (s)')
    plt.ylabel('Acceleration (m/s²)')
    plt.title(f'{rocket_name} - Acceleration vs Time')
    plt.grid(True)
    plt.legend()
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python visualize.py <rocket_name>")
    else:
        visualize(sys.argv[1])
