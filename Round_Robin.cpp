
// C++ program for implementation of RR scheduling.
// For simplicity i have only considered 10 proceses of maximum.
#include <bits/stdc++.h>
using namespace std;

struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
};

int main()
{

    int n;
    int quantum;
    struct process p[10];
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int burst_remaining[10];
    int current_t = 0;

    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter time quantum: ";
    cin >> quantum;

    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        cout << "Enter arrival time of process " << i + 1 << ": ";
        cin >> p[i].arrival_time;
        cout << "Enter burst time of process " << i + 1 << ": ";
        cin >> p[i].burst_time;
        burst_remaining[i] = p[i].burst_time;
        cout << endl;
    }

    // Keep traversing processes in round robin manner until all of them are done.
    while (1)
    {
        bool done = true;

        for (int i = 0; i < n; i++)
        {
            if (burst_remaining[i] > 0)
            {
                done = false;

                if (burst_remaining[i] > quantum)
                {
                    current_t += quantum;

                    burst_remaining[i] -= quantum;
                }
                else
                {
                    current_t += burst_remaining[i];
                    p[i].waiting_time = current_t - p[i].burst_time;
                    p[i].turnaround_time = p[i].burst_time + p[i].waiting_time;
                    burst_remaining[i] = 0;
                }
            }
        }
        if (done == true)
            break;
    }
    // Display processes along with all details
    cout << "Processes "
         << " Burst time "
         << " Waiting time "
         << " Turn around time\n";

    // Calculate total waiting time and total turn around time.
    for (int i = 0; i < n; i++)
    {
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
        cout << "\nP"
             << i + 1 << "\t\t" << p[i].burst_time << "\t "
             << p[i].waiting_time << "\t\t " << p[i].turnaround_time << endl;
    }
    cout << "Average waiting time = "
         << (float)total_waiting_time / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_turnaround_time / (float)n;

    return 0;
}