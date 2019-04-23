#include<stdio.h>

struct Process{
	char Pname;
	int ArrivalTime,BurstTime,WaitingTime,ResponseTime,TurnAroundTime;
	int Completed;
	float ntt;
}P[10],P1[10];


int n,n1;
int q[10],q1[10];
int Front = -1, Rear = -1, Front1 = -1, Rear1 = -1;


void Enqueue(int i){
    if(Rear == 10)
        printf("Overflow");
    Rear++;
    q[Rear] = i;
    if(Front == -1)
        Front = 0;
}

int Dequeue(){
    if(Front == -1)
        printf("Underflow");
    int Temp = q[Front];
    if(Front == Rear)
        Front = Rear = -1;
    else
        Front++;
    return Temp;
}


int PinQueue(){
    int k;
    for(k = Front; k <= Rear; k++){
        if(q[k] == i)
            return 1;
    }
    return 0;
}


void Enqueue1(){
    if(Rear1 == 10)
        printf("Overflow");
    Rear1++;
    q1[Rear1] = i;
    if(Front1 == -1)
        Front1 = 0;
}

int Dequeue1(){
    if(Front1 == -1)
        printf("Underflow");
    int Temp1=q1[Front1];
    if(Front1 == Rear1)
        Front1 = Rear1 = -1;
    else
        Front1++;
    return Temp1;
}

int PinQueue1(){
    int k;
    for(k = Front1; k <= Rear1; k++){
        if(q1[k] == i)
            return 1;
    }
    return 0;
}
