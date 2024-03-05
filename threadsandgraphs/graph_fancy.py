import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Load data
data = pd.read_csv("threads.dat")

# Calculate average execution time for each number of threads
avgs = data.groupby(["Threads"]).mean().reset_index()

# Indicate whether each data point is original or average
data["isAvg"] = data.shape[0] * ["Execution Time"]
avgs["isAvg"] = avgs.shape[0] * ["Average Execution Time"]

# Combine data for plotting
all_data = pd.concat([data, avgs])

# Plot
sns.set_theme(style="darkgrid")

fig, ax = plt.subplots()
sns.scatterplot(data=all_data, x="Threads", y="Time (seconds)", 
                hue="isAvg", s=50, ax=ax)      # 's' sets marker size
sns.lineplot(data=avgs, x="Threads", y="Time (seconds)", ax=ax,
             color="tab:orange")

plt.title("Duration of Multi-Threaded Quicksort", fontsize=14)
plt.savefig("threads-graph.png")