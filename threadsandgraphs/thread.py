import csv
import matplotlib.pyplot as plt 

data_list = []
data_dict = {}

# Read data from file
with open("threads.dat") as csvfile:
    reader = csv.reader(csvfile)
    for i, row in enumerate(reader):
        if i == 0: continue     # Skip header
        # Get (threads, execution time) from row
        # Columns = Run, Threads, Time
        threads, time = int(row[1]), float(row[2])
        
        data_list.append((threads, time))
        
        if threads in data_dict:
            data_dict[threads].append(time)
        else:
            data_dict[threads] = [time]
            
# Calculate average time for each thread count
avgs = [(t, sum(data_dict[t]) / len(data_dict[t])) for t in data_dict.keys()]

# Prepare data for plotting
x1, y1 = zip(*data_list)
x2, y2 = zip(*avgs)

# Plot data
plt.scatter(x1, y1, s=50)
plt.scatter(x2, y2, color='tab:orange', s=50)
plt.plot(x2, y2, color='tab:orange')

# Adjust fig
plt.grid()
plt.xlabel("Threads", fontsize=12)
plt.ylabel("Time (seconds)", fontsize=12)
plt.title("Duration of Multi-Threaded Quicksort", fontsize=14)
plt.legend(labels=["Execution Time", "Average Execution Time"])

# Save fig
plt.savefig("threads-graph.png")