enqueue(0);          // enqueue the first process
	enqueue1(0);
	struct process *q11 = p;
	int time_qq = 0;
	int cur_pp = 0;
	int num = n;
	printf("\n\nProcess execution order: ");
	for(time=q11[0].at;time<sum_bt;)       // run until the total burst time reached
	{
		int el;
		if(time_qq >= tqqq || rear == front || rear1 == front1)
		{
			if(cur_pp == 0)
			{
				cur_pp = 1;
				q11 = p1;
				num = n1;
			}
			else
			{
				cur_pp = 0;
				q11 = p;
				num = n;
			}

			time_qq = 0;
		}
		if(cur_pp == 0)
		i=dequeue();
		else
		i = dequeue1();

		el = q11[i].rt;
		if(q11[i].completed == 1){
			if(cur_pp == 0){
			q11 = p1;
			cur_pp = 1;
			num = n1;
			}
			else{
			q11 = p;
			cur_pp = 0;
			num = n;
			}
			time_qq = 0;
			continue;
		}
		if(q11[i].rt<=tq && tqqq - time_qq >= el)
		{ /* for processes having remaining time with less than or  equal  to time quantum  */
			time+=q11[i].rt;
			q11[i].rt=0;
			q11[i].completed=1;
			printf(" %c | ",q11[i].name);
			q11[i].wt=time-q11[i].at-q11[i].bt;
			q11[i].tt=time-q11[i].at;
			q11[i].ntt=((float)q11[i].tt/q11[i].bt);
			for(j=0;j<num;j++)                /*enqueue the processes which have come  while scheduling */
			{
				if(q11[j].at<=time && q11[j].completed!=1)
				{
					if(cur_pp == 0) {
					if(isInQueue(j) != 1)
					enqueue(j);
					}
					else {
					if(isInQueue1(j) != 1)
					enqueue1(j);
					}
				}
			}
		}
		else               // more than time quantum
		{
			if(tqqq - time_qq < el)
			el = tqqq - time_qq;
			else
			el = tq;
			time+= el;
			q11[i].rt-=el;
			printf(" %c | ",q11[i].name);
			if(q11[i].rt == 0)
				q11[i].completed = 1;

			for(j=0;j<num;j++)    /*first enqueue the processes which have come while scheduling */
			{
				if(q11[j].at<=time && q11[j].completed!=1&&i!=j)
				{
					if(cur_pp == 0) {
					if(isInQueue(j) != 1)
					enqueue(j);
					}
					else{
					if(isInQueue1(j) != 1)
					enqueue1(j);
					}
				}
			}
			if(q11[i].rt != 0){
			if(cur_pp == 0)
			enqueue(i);   // then enqueue the uncompleted process
			else
			enqueue1(i);
			}
		}

		time_qq += el;
	}


	printf("\n\n\n\nName\tArrival Time\tBurst Time\tWaiting Time\tTurnAround Time");
	for(i=0;i<n;i++)
	{
		avgwt+=q11[i].wt;
		avgtt+=q11[i].tt;
		printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d",q11[i].name,q11[i].at,q11[i].bt,q11[i].wt,q11[i].tt);
	}



	//printf("\nName\tArrival Time\tBurst Time\tWaiting Time\tTurnAround Time);
	for(i=0;i<n1;i++)
	{
		avgwt+=p1[i].wt;
		avgtt+=p1[i].tt;
		printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d",p1[i].name,p1[i].at,p1[i].bt,p1[i].wt,p1[i].tt);
	}

	printf("\n\n\nAverage waiting time: %f\n",avgwt/(n + n1));
	printf("\n\nAverage turnaround time: %f\n",avgtt/(n + n1));
	printf("\n\nTotal Time Spent: %f\n",avgtt);

}
