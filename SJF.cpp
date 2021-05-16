// C++ program for implementation of SJF scheduling.
// For simplicity of the code implementation i have considered maximum of 10 process.

#include <bits/stdc++.h>
using namespace std;

// Creating a structure helps to keep all the information of each process in a single system.
struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

int main()
{
    int n;
    struct process p[10];
    float avg_turnaround_time;
    float avg_waiting_time;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int is_completed[10];
    memset(is_completed, 0, sizeof(is_completed));

    cout << "Enter the number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        cout << "Enter arrival time of process " << i + 1 << ": ";
        cin >> p[i].arrival_time;
        cout << "Enter burst time of process " << i + 1 << ": ";
        cin >> p[i].burst_time;
        cout << endl;
    }

    int current_time = 0;
    int completed = 0;

    // Checking if all the process has already completed executing.
    while (completed != n)
    {
        int idx = -1;
        int mini = 10000000;

        // Checking all the available process at the current time and taking the process with the least burst time.
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrival_time <= current_time && is_completed[i] == 0)
            {
                if (p[i].burst_time < mini)
                {
                    mini = p[i].burst_time;
                    idx = i;
                }

                // incase of equal burst time, as the rule suggest the process that comes early should be executed first.
                if (p[i].burst_time == mini)
                {
                    if (p[i].arrival_time < p[idx].arrival_time)
                    {
                        mini = p[i].burst_time;
                        idx = i;
                    }
                }
            }
        }

        // Calculating all the attributes of the process.
        if (idx != -1)
        {
            p[idx].start_time = current_time;
            p[idx].completion_time = p[idx].start_time + p[idx].burst_time;
            p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;

            total_turnaround_time += p[idx].turnaround_time;
            total_waiting_time += p[idx].waiting_time;

            is_completed[idx] = 1;
            completed++;
            current_time = p[idx].completion_time;
        }
        else
        {
            current_time++;
        }
    }

    avg_turnaround_time = (float)total_turnaround_time / n;
    avg_waiting_time = (float)total_waiting_time / n;

    cout << endl
         << endl;

    // Display processes along with all details
    cout << "Processes "
         << " Burst time "
         << " Waiting time "
         << " Turn around time\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nP"
             << i + 1 << "\t\t" << p[i].burst_time << "\t "
             << p[i].waiting_time << "\t\t " << p[i].turnaround_time << endl;
    }

    cout << "Average Turnaround Time = " << avg_turnaround_time << endl;
    cout << "Average Waiting Time = " << avg_waiting_time << endl;
    return 0;
}
