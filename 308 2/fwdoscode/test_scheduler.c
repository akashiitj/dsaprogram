#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
// A list of Processes will be maintained in the Memory
#define SHMSZ 27
#define procNos 5

typedef struct procStruct
{
    pid_t ids[procNos];
    int arrSize[procNos];
    int priority[procNos];
    int fin[procNos];
    int count;

} procStruct;
struct process
{
	int pid;
	int priority;
	int burst;
	struct process *next;
	struct process *previous;
};

// Function to take List of processes as input
/*int Print_Schedule(struct process *beg)
{
	struct process *new;
	int i=0,time_arr[10];
	float sum=0;

	new=beg;
	printf("\n\n");
	do
	{
		printf("Process Id : %d |",new->pid);
		new=new->next;
	}

	while(new!=NULL); // No Process in the Queue Busy Waiting 

	printf("\n");
	new=beg;
	do
	{
		if(i==0)
			time_arr[i]=new->burst ;
		else
			time_arr[i]=time_arr[i-1]+new->burst ;
		//printf(" Time Taken by  : %d ",arr[i]);
		sum=sum+time_arr[i];
		new=new->next;
		i++;
	}
	while(new!=NULL);
	//printf("\n\n\t Total Time Taken : %f units",sum);
	//sum=sum/i;
	//printf("\n\n\t Average Time Taken : %f units",sum);
	return 0;
}*/


void fcfs(procStruct *beg)
{
	int cnt=beg->count;
	int i=0;

	struct timespec t_beg,t_fin,t_base;

	clock_gettime(CLOCK_MONOTONIC, &t_base);

	for(i=0;i<cnt;i++)
	{
		clock_gettime(CLOCK_MONOTONIC, &t_beg);
		kill(beg->ids[i],SIGCONT);

		kill(getpid(),SIGSTOP);
		clock_gettime(CLOCK_MONOTONIC, &t_fin);

		printf("\nProcess #%d:\t Start: %f\t End: %f\n",i,(t_beg.tv_sec + t_beg.tv_nsec/1000000000.0) - (t_base.tv_sec + t_base.tv_nsec/1000000000.0),(t_fin.tv_sec + t_fin.tv_nsec/1000000000.0) - (t_base.tv_sec + t_base.tv_nsec/1000000000.0));
	}

}


void priority_scheduling(procStruct* beg)
{
	int cnt=beg->count;
	int min,temp,swap;

	int i,j;
	for(i=0;i<cnt;i++)
    {
    	min=beg->priority[i];
        for(j=i+1;j<cnt;j++)
        {
            if(min > beg->priority[j])
            {
            	min=beg->priority[j];

            	temp=beg->priority[i];
            	beg->priority[i]=beg->priority[j];
            	beg->priority[j]=temp;

            	temp=beg->ids[i];
            	beg->ids[i]=beg->ids[j];
            	beg->ids[j]=temp;

            	temp=beg->arrSize[i];
            	beg->arrSize[i]=beg->arrSize[j];
            	beg->arrSize[j]=temp;

            	temp=beg->fin[i];
            	beg->fin[i]=beg->fin[j];
            	beg->fin[j]=temp;
            }
        }    
    }


    struct timespec t_beg,t_fin,t_base;

	clock_gettime(CLOCK_MONOTONIC, &t_base);

	for(i=0;i<cnt;i++)
	{
		clock_gettime(CLOCK_MONOTONIC, &t_beg);
		kill(beg->ids[i],SIGCONT);

		kill(getpid(),SIGSTOP);
		clock_gettime(CLOCK_MONOTONIC, &t_fin);

		printf("\nProcess #%d:\t Start: %f\t End: %f\n",i,(t_beg.tv_sec + t_beg.tv_nsec/1000000000.0) - (t_base.tv_sec + t_base.tv_nsec/1000000000.0),(t_fin.tv_sec + t_fin.tv_nsec/1000000000.0) - (t_base.tv_sec + t_base.tv_nsec/1000000000.0));
	}

}

void Shortest_Job_First(procStruct* beg)
{
	int cnt=beg->count;
	int min,temp,swap;
	int i,j;
	for(i=0;i<cnt;i++)
    {
    	min=beg->arrSize[i];
        for(j=i+1;j<cnt;j++)
        {
            if(min > beg->arrSize[j])
            {
            	min=beg->arrSize[j];

            	temp=beg->arrSize[i];
            	beg->arrSize[i]=beg->arrSize[j];
            	beg->arrSize[j]=temp;

            	temp=beg->ids[i];
            	beg->ids[i]=beg->ids[j];
            	beg->ids[j]=temp;

            	temp=beg->priority[i];
            	beg->priority[i]=beg->priority[j];
            	beg->priority[j]=temp;

            	temp=beg->fin[i];
            	beg->fin[i]=beg->fin[j];
            	beg->fin[j]=temp;
            }
        }    
    }
    
    struct timespec t_beg,t_fin,t_base;

	clock_gettime(CLOCK_MONOTONIC, &t_base);

	for(i=0;i<cnt;i++)
	{
		clock_gettime(CLOCK_MONOTONIC, &t_beg);
		kill(beg->ids[i],SIGCONT);

		kill(getpid(),SIGSTOP);
		clock_gettime(CLOCK_MONOTONIC, &t_fin);

		printf("\nProcess #%d:\t Start: %f\t End: %f\n",i,(t_beg.tv_sec + t_beg.tv_nsec/1000000000.0) - (t_base.tv_sec + t_base.tv_nsec/1000000000.0),(t_fin.tv_sec + t_fin.tv_nsec/1000000000.0) - (t_base.tv_sec + t_base.tv_nsec/1000000000.0));
	}

}


void RR_scheduling(procStruct *beg)
{
	struct timespec t_slot;
	t_slot.tv_sec = 0;
	t_slot.tv_nsec = 10;

	struct timespec t_remain;
	struct timespec t_base, t_beg, t_fin;

	int i;
	int cnt=beg->count;

	int fin_cnt = 0;

	i = 0;

	clock_gettime(CLOCK_MONOTONIC, &t_base);
	while(fin_cnt < cnt)
	{
		if(beg->fin[i] == 1)
		{
			i = (i+1)%cnt;
			continue;
		}
		else
		{
			clock_gettime(CLOCK_MONOTONIC, &t_beg);
			kill(beg->ids[i],SIGCONT);

			clock_nanosleep(CLOCK_MONOTONIC, 0, &t_slot, &t_remain);
			clock_gettime(CLOCK_MONOTONIC, &t_fin);

			if(beg->fin[i] == 0)
			{
				kill(beg->ids[i],SIGSTOP);
				printf("Process #%d used cycle\t Start: %f\t End: %f\n",beg->ids[i],(t_beg.tv_sec + t_beg.tv_nsec/1000000000.0) - (t_base.tv_sec + t_base.tv_nsec/1000000000.0),(t_fin.tv_sec + t_fin.tv_nsec/1000000000.0) - (t_base.tv_sec + t_base.tv_nsec/1000000000.0));
				i = (i+1)%cnt;
				continue;
			}
			else
			{
				printf("Process #%d finished at: %f\n",beg->ids[i],(t_fin.tv_sec + t_fin.tv_nsec/1000000000.0) - (t_base.tv_sec + t_base.tv_nsec/1000000000.0));	
				fin_cnt++;
				i = (i+1)%cnt;
				continue;
			}
			
		}
	}

}


int main()
{

	key_t procShmKey = 1111;
    int procShmId;
    procStruct *procShm;

    if((procShmId = shmget(procShmKey, SHMSZ, IPC_CREAT | 0666)) < 0)
    {
        printf("ERROR IN shmget");
        return;
    }
    if((procShm = shmat(procShmId, NULL, 0)) == (procStruct*) -1)
    {
        printf("ERROR IN shmat");
        return;
    }

    key_t schedShmKey = 2222;
    int schedShmId;
    pid_t *schedShm;

    if((schedShmId = shmget(schedShmKey, SHMSZ, IPC_CREAT | 0666)) < 0)
    {
        printf("ERROR IN shmget");
        return;
    }
    if((schedShm = shmat(schedShmId, NULL, 0)) == (pid_t*) -1)
    {
        printf("ERROR IN shmat");
        return;
    }
    *schedShm=getpid();
    int ch;
	while(1)
	{
		printf("\n\t1. First Come First serve ");
		printf("\n\t2. Priority Based Scheduling");
		printf("\n\t3. Shortest Job First ");
		printf("\n\t4. Round Robin Scheduling");
		printf("\n\t5. EXIT");
		printf("\n\t Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:fcfs(procShm);
				   break;
			case 2:priority_scheduling(procShm);
				   break;
			case 3:Shortest_Job_First(procShm);
			       break;
			case 4:RR_scheduling(procShm);
		           break;
		    case 5:exit(0);
		    	   break;

		    default: printf("Invalid Choice !!!\n");
		}

	}
	return 0;
}



