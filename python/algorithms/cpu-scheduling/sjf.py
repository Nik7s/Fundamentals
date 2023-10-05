# Alexander Luna | Assignment 3 | 10/3/2023
# Shorted Job First CPU Scheduling Algorithm

def sjf(processes, burst_times):
    n = len(processes)
    
    # Create a list of tuples (process, burst_time)
    process_burst_time = [(processes[i], burst_times[i]) for i in range(n)]
    
    # Sort processes by burst time in ascending order
    process_burst_time.sort(key=lambda x: x[1])
    
    # Initialize waiting time and turnaround time arrays with zeros
    waiting_time = [0] * n
    turnaround_time = [0] * n
    
    # Calculate waiting time for each process
    for i in range(1, n):
        waiting_time[i] = waiting_time[i - 1] + process_burst_time[i - 1][1]
    
    # Calculate turnaround time for each process
    for i in range(n):
        turnaround_time[i] = waiting_time[i] + process_burst_time[i][1]
    
    # Calculate average waiting time and average turnaround time
    avg_waiting_time = sum(waiting_time) / n
    avg_turnaround_time = sum(turnaround_time) / n
    
    # Print the results
    print("Process\tBurst Time\tWaiting Time\tTurnaround Time")
    for i in range(n):
        process, burst_time = process_burst_time[i]
        print(f"{process}\t\t{burst_time}\t\t{waiting_time[i]}\t\t{turnaround_time[i]}")
    
    print(f"Average Waiting Time: {avg_waiting_time:.2f}")
    print(f"Average Turnaround Time: {avg_turnaround_time:.2f}")

if __name__ == "__main__":
    processes = ["P1", "P2", "P3", "P4"]
    burst_times = [6, 8, 7, 3]
    
    sjf(processes, burst_times)