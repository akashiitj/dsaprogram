#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <time.h>
#define SHMSZ 27
#define procNos 5
#define ARRLEN 10000

typedef struct procStruct
{
    pid_t ids[procNos];
    int arrSize[procNos];
    int priority[procNos];
    int fin[procNos];
    int count;

} procStruct;

void bubbleSort(int[],int);

void main()
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

    procShm->count = 0;

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

    int i;
    pid_t childPid;
    for(i = 0; i < procNos; i++)
    {
        childPid = fork();
        if(childPid == 0)
        {
            //CREATE DATA
            int arr[ARRLEN/(i+1)];
            int j;

            for(j=0;j<ARRLEN/(i+1);j++)
            {
                arr[j] = ARRLEN/(i+1) - j;
            }

            printf("%d says HI!\n", getpid());

            kill(getpid(),SIGSTOP);
            bubbleSort(arr,ARRLEN/(i+1));
            //printf("DONE:\n");
            printf("%d\t\t%d\t\t%d\n",getpid(),(i*2)%procNos,ARRLEN/(i+1));

            for(j=0;j<procNos;j++)
            {
                if(procShm->ids[j] == getpid())
                {
                    procShm->fin[j] = 1;
                    break;
                }
            }

            kill(*schedShm,SIGCONT);
            kill(getpid(),SIGKILL);
        }
        else
        {
            printf("%d\n", childPid);
            procShm->ids[i] = childPid;
            procShm->arrSize[i] = ARRLEN/(i+1);
            procShm->priority[i]= (i*2)%procNos;
            procShm->fin[i] = 0;
            procShm->count++;
            //PARENT
        }
    }
    sleep(100000);
}

void bubbleSort(int arr[], int len)
{
    int i;
    int j;
    int temp;
    for(i=0;i<len;i++)
    {
        for(j=0;j<len-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
