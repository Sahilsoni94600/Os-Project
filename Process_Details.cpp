#include<stdio.h>

int main(){
    int i, j, TimeQuantum;
    int time = 0, time1 = 0;
    int Sum_BurstTime = 0, Sum_BurstTime1 = 0;
    char c, d;
    float Average_WaitingTime = 0, Average_TurnAroundTime = 0, Average_WaitingTime1 = 0, Average_TurnAroundTime1 = 0;
    printf("Enter no. of Student Queries: ");
    scanf("%d", &n);


    for(i = 0, c = 'A'; i < n; i++, c++){
        P[i].Pname = c;
        printf("Enter Arrival Time and Burst Time for Process %c : ", P[i].Pname);
        scanf("%d%d", &P[i].ArrivalTime, &P[i].BurstTime);
        P[i].ResponseTime = P[i].BurstTime;
        P[i].Completed = 0;
        Sum_BurstTime += P[i].BurstTime;
    }

    printf("Enter no. of Faculty Queries: ");
    scanf("%d", &n1);


    for(i = 0, d = 'a'; i < n1; i++, d++){
        P1[i].Pname = d;
        printf("Enter Arrival Time and Burst Time for Process %d", P1[i].Pname);
        scanf("%d%d", &P1[i].ArrivalTime, &P1[i].BurstTime);
        P1[i].ResponseTime = P1[i].BurstTime;
        P1[i].Completed = 0;
        Sum_BurstTime += P1[i].BurstTime;
    }

    int TimeQuantum1;
    printf("Enter Time Quantum for Round Robin among the Processes: ");
    scanf("%d", &TimeQuantum);

    printf("Enter Time Quantum for Round Robin among the Multilevel Queues: ");
    scanf("%d", &TimeQuantum1);