// C++ program for implementation of FCFS scheduling.
// For simplicity i have considered of taking maximum 10 process.
// I have also assumed that all processes have arrived at the same time in a accending order like processnumber.
// Less process number appreared early in the arrival order.

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cout << "Enter total process number(must be less than 10) :";
    cin >> n;

    int burstTime[10];
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout << "Enter burst time for process P" << i + 1 << " :";
        cin >> burstTime[i];
    }

    int waitingTime[10];

    // First process donn't have to wait.
    waitingTime[0] = 0;
    for (int i = 1; i < n; i++)
    {
        waitingTime[i] = 0;

        // Waiting time of any process in FCFS scheduing is the sum of burst time of it's previous all processes.
        for (int j = 0; j < i; j++)
        {
            waitingTime[i] += burstTime[j];
        }
    }

    // Turn around time = waiting time + burst time
    int turnATime[10];
    for (int i = 0; i < n; i++)
    {
        turnATime[i] = waitingTime[i] + burstTime[i];
    }

    // Calculating Average waiting time & turn around time for each process.
    float avgwt = 0.0;
    float avgtat = 0.0;
    for (int i = 0; i < n; i++)
    {
        avgtat += turnATime[i];
        avgwt += waitingTime[i];
    }
    avgwt /= n;
    avgtat /= n;

    cout << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
    for (int i = 0; i < n; i++)
    {
        cout << "\nP" << i + 1 << "\t\t" << burstTime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnATime[i];
    }

    cout << "\nAverage waiting time : " << avgwt << endl;
    cout << "Average turn around time : " << avgtat << endl;

    return 0;
}