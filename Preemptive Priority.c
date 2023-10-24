#include <stdio.h>

struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

int main()
{
    int n;
    struct process p[100];
    float avg_turnaround_time = 0;
    float avg_waiting_time = 0;
    float cpu_utilisation = 0;
    float cpu_idle = 0;
    float throughput = 0;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_idle_time = 0;
    int burst_remaining[100];
    int is_completed[100];

    for (int i = 0; i < 100; i++)
    {
        is_completed[i] = 0;
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time, burst time, and priority of process %d: ", i + 1);
        scanf("%d %d %d", &p[i].arrival_time, &p[i].burst_time, &p[i].priority);
        p[i].pid = i + 1;
        burst_remaining[i] = p[i].burst_time;
    }

    int current_time = 0;
    int completed = 0;
    int prev = 0;

    while (completed != n)
    {
        int idx = -1;
        int highest_priority = 10000000;

        for (int i = 0; i < n; i++)
        {
            if (p[i].arrival_time <= current_time && is_completed[i] == 0 && p[i].priority < highest_priority)
            {
                idx = i;
                highest_priority = p[i].priority;
            }
        }

        if (idx != -1)
        {
            if (burst_remaining[idx] == p[idx].burst_time)
            {
                p[idx].start_time = current_time;
                total_idle_time += p[idx].start_time - prev;
            }
            burst_remaining[idx] -= 1;
            current_time++;
            prev = current_time;

            if (burst_remaining[idx] == 0)
            {
                p[idx].completion_time = current_time;
                p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
                p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;

                total_turnaround_time += p[idx].turnaround_time;
                total_waiting_time += p[idx].waiting_time;

                is_completed[idx] = 1;
                completed++;
            }
        }
        else
        {
            current_time++;
        }
    }

    int min_arrival_time = 10000000;
    int max_completion_time = -1;

    for (int i = 0; i < n; i++)
    {
        min_arrival_time = (p[i].arrival_time < min_arrival_time) ? p[i].arrival_time : min_arrival_time;
        max_completion_time = (p[i].completion_time > max_completion_time) ? p[i].completion_time : max_completion_time;
    }

    avg_turnaround_time = (float)total_turnaround_time / n;
    avg_waiting_time = (float)total_waiting_time / n;
    cpu_utilisation = ((float)(max_completion_time - total_idle_time) / max_completion_time) * 100;
    throughput = (float)n / (max_completion_time - min_arrival_time);
    cpu_idle = ((float)(total_idle_time)/max_completion_time)*100;
    printf("\nPid\tAT\tBT\tPri\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].priority, p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
    }

    printf("Average Turnaround Time = %.2f\n", avg_turnaround_time);
    printf("Average Waiting Time = %.2f\n", avg_waiting_time);
    printf("Throughput = %.2f processes/unit time\n", throughput);
    printf("CPU Utilization = %.2f%%\n", cpu_utilisation);
    printf("CPU Idle = %.2f%%\n", cpu_idle);
    return 0;
}
