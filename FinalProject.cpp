#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <unistd.h>  //Header file for sleep(). 
#include <pthread.h>

struct process
{
	char Pname;
	int ArrivalTime,BurstTime,WaitingTime,TurnAroundTime,ResponseTime;
	int Completed;
	float ntt;
}P[10], P1[10];



int n,n1;
int q[10],q1[10];  //queue
int Front=-1,Rear=-1, Front1=-1,Rear1=-1;


void Enqueue(int i)
{
	if(Rear==10)
		printf("overflow");
	Rear++;
	q[Rear]=i;
	if(Front==-1)
		Front=0;
}

int Dequeue()
{
	if(Front==-1)
		printf("underflow");
	int temp=q[Front];
	if(Front==Rear)
		Front=Rear=-1;
	else
		Front++;
	return temp;
}

int PinQueue(int i)
{
	int k;
	for(k=Front;k<=Rear;k++)
	{
		if(q[k]==i)
			return 1;
	}
	return 0;
}


void Enqueue1(int i)
{
	if(Rear1==10)
		printf("overflow");
	Rear1++;
	q1[Rear1]=i;
	if(Front1==-1)
		Front1=0;
}

int Dequeue1()
{
	if(Front1==-1)
		printf("underflow");
	int temp1=q1[Front1];
	if(Front1==Rear1)
		Front1=Rear1=-1;
	else
		Front1++;
	return temp1;
}

int PinQueue1(int i)
{
	int k;
	for(k=Front1;k<=Rear1;k++)
	{
		if(q1[k]==i)
			return 1;
	}
	return 0;
}

int main()
{
      printf(" \n");
	  printf(" \n");
	  printf("\t\t\t\t ================================================= \n");
	  printf("\t\t\t\t||                                               || \n");
	  printf("\t\t\t\t||\t   ___      ____    ____   ______   \t ||\n");
	  printf("\t\t\t\t||\t .'   `.   |_   \\  /   _|.' ____ \\   \t || \n");
	  printf("\t\t\t\t||\t/  .-.  \\    |   \\/   |  | (___ \\_|   \t ||\n");
	  printf("\t\t\t\t||\t| | \\ | |    | |\\  /| |   _.____`.    \t ||\n");
	  printf("\t\t\t\t||\t\\  `-'  \\_  _| |_\\/_| |_ | \\____) |   \t ||\n");
	  printf("\t\t\t\t||\t `.___.\\__||_____||_____| \\______.'   \t ||\n");
	  printf("\t\t\t\t||                                               || \n");
	  sleep(1); 
	  printf(" \t\t\t\t||\t  ___(Query Management System)___\t ||\n");
	  printf("\t\t\t\t ================================================= \n");
	  sleep(1); 
	  system("COLOR 17");
	  sleep(1); 
	  system("COLOR 47");
	  sleep(1); 
	  system("COLOR 60");
	  printf(" ---------------------------------------------------------------------------------------------------------------------");
	int i,j,Time=0,Sum_BurstTime=0,TimeQuantum,Time1=0,Sum_BurstTime1=0;
	char c,d;
	float Average_WaitingTime=0, Average_TurnAroundTime=0, Average_WaitingTime1=0, Average_TurnAroundTime1=0;
	printf("\n\nEnter no of processes in student:");
	scanf("%d",&n);

	for(i=0,c='A';i<n;i++,c++)
	{
		P[i].Pname=c;
		printf("Enter the arrival Time and burst Time of process %c: ",P[i].Pname);
		scanf("%d%d",&P[i].ArrivalTime,&P[i].BurstTime);
		P[i].ResponseTime=P[i].BurstTime;
		P[i].Completed=0;
		Sum_BurstTime+=P[i].BurstTime;

	}

	printf("Enter no of processes in faculty:");
	scanf("%d",&n1);

	for(i=0,d='a';i<n1;i++,d++)
	{
		P1[i].Pname=d;
		printf("Enter the arrival Time and burst Time of process %c: ",P1[i].Pname);
		scanf("%d%d",&P1[i].ArrivalTime,&P1[i].BurstTime);
		P1[i].ResponseTime=P1[i].BurstTime;
		P1[i].Completed=0;
		Sum_BurstTime+=P1[i].BurstTime;

	}

int TimeQuantum1;
	printf("\nEnter the Time quantum:");
	scanf("%d",&TimeQuantum);

	printf("Enter Time quatum for queues: ");
	scanf("%d", &TimeQuantum1);

	//sortByArrival();
	//sortByArrival1();
	Enqueue(0);          // Enqueue the first process
	Enqueue1(0);
	struct process *Queue = P;
	int Time_Queue = 0;
	int Current_Process = 0;
	int Num = n;
	printf("\n\nProcess execution order: ");
	for(Time=Queue[0].ArrivalTime;Time<Sum_BurstTime;)       // run until the total burst Time reached
	{
		int el;
		if(Time_Queue >= TimeQuantum1 || Rear == Front || Rear1 == Front1)
		{
			if(Current_Process == 0)
			{
				Current_Process = 1;
				Queue = P1;
				Num = n1;
			}
			else
			{
				Current_Process = 0;
				Queue = P;
				Num = n;
			}

			Time_Queue = 0;
		}
		if(Current_Process == 0)
		i=Dequeue();
		else
		i = Dequeue1();

		el = Queue[i].ResponseTime;
		if(Queue[i].Completed == 1){
			if(Current_Process == 0){
			Queue = P1;
			Current_Process = 1;
			Num = n1;
			}
			else{
			Queue = P;
			Current_Process = 0;
			Num = n;
			}
			Time_Queue = 0;
			continue;
		}
		if(Queue[i].ResponseTime<=TimeQuantum && TimeQuantum1 - Time_Queue >= el)
		{ /* for processes having remaining Time with less than or  equal  to Time quantum  */
			Time+=Queue[i].ResponseTime;
			Queue[i].ResponseTime=0;
			Queue[i].Completed=1;
			printf(" %c | ",Queue[i].Pname);
			Queue[i].WaitingTime=Time-Queue[i].ArrivalTime-Queue[i].BurstTime;
			Queue[i].TurnAroundTime=Time-Queue[i].ArrivalTime;
			Queue[i].ntt=((float)Queue[i].TurnAroundTime/Queue[i].BurstTime);
			for(j=0;j<Num;j++)                /*Enqueue the processes which have come  while scheduling */
			{
				if(Queue[j].ArrivalTime<=Time && Queue[j].Completed!=1)
				{
					if(Current_Process == 0) {
					if(PinQueue(j) != 1)
					Enqueue(j);
					}
					else {
					if(PinQueue1(j) != 1)
					Enqueue1(j);
					}
				}
			}
		}
		else               // more than Time quantum
		{
			if(TimeQuantum1 - Time_Queue < el)
			el = TimeQuantum1 - Time_Queue;
			else
			el = TimeQuantum;
			Time+= el;
			Queue[i].ResponseTime-=el;
			printf(" %c | ",Queue[i].Pname);
			if(Queue[i].ResponseTime == 0)
				Queue[i].Completed = 1;

			for(j=0;j<Num;j++)    /*first Enqueue the processes which have come while scheduling */
			{
				if(Queue[j].ArrivalTime<=Time && Queue[j].Completed!=1&&i!=j)
				{
					if(Current_Process == 0) {
					if(PinQueue(j) != 1)
					Enqueue(j);
					}
					else{
					if(PinQueue1(j) != 1)
					Enqueue1(j);
					}
				}
			}
			if(Queue[i].ResponseTime != 0){
			if(Current_Process == 0)
			Enqueue(i);   // then Enqueue the uncompleted process
			else
			Enqueue1(i);
			}
		}

		Time_Queue += el;
	}


	printf("\n\n\n\nProcess Name\tArrival Time\tBurst Time\tWaiting Time\tTurnAround Time");
	for(i=0;i<n;i++)
	{
		Average_WaitingTime+=Queue[i].WaitingTime;
		Average_TurnAroundTime+=Queue[i].TurnAroundTime;
		printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d",Queue[i].Pname,Queue[i].ArrivalTime,Queue[i].BurstTime,Queue[i].WaitingTime,Queue[i].TurnAroundTime);
	}



	//printf("\nProcess Name\tArrival Time\tBurst Time\tWaiting Time\tTurnAround Time);
	for(i=0;i<n1;i++)
	{
		Average_WaitingTime+=P1[i].WaitingTime;
		Average_TurnAroundTime+=P1[i].TurnAroundTime;
		printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d",P1[i].Pname,P1[i].ArrivalTime,P1[i].BurstTime,P1[i].WaitingTime,P1[i].TurnAroundTime);
	}

	printf("\n\n\nAverage waiting Time: %f\n",Average_WaitingTime/(n + n1));
	printf("\n\nAverage turnaround Time: %f\n",Average_TurnAroundTime/(n + n1));
	printf("\n\nTotal Time Spent: %f\n",Average_TurnAroundTime);

}
