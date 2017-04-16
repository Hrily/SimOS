#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>

pthread_mutex_t x,wsem;
pthread_t tidC[20],tidP[20];
int readcount;

void intialize()
{	printf("\nhello\n");
    pthread_mutex_init(&x,NULL);
    pthread_mutex_init(&wsem,NULL);
    readcount=0;
}

void  *reader (void *param)
{
    int waittime;
    int *ind = (int *)param;
   // waittime = rand() % 5;
    printf("\nReader  %d is trying to enter",*ind);
    pthread_mutex_lock(&x);
    readcount++;
    if(readcount==1)
        pthread_mutex_lock(&wsem);
    printf("\n Reader %d is inside ",*ind);
    pthread_mutex_unlock(&x);
    //sleep(waittime);
    pthread_mutex_lock(&x);
    readcount--;
    if(readcount==0)
        pthread_mutex_unlock(&wsem);
    pthread_mutex_unlock(&x);
    printf("\nReader %d is Leaving",*ind);
}   

void  *writer (void *param)
{
    int waittime;
    int *ind = (int *)param;
    waittime=rand() % 3;
    printf("\nWriter %d is trying to enter",*ind);
    pthread_mutex_lock(&wsem);
    printf("\nWriter %d has entered",*ind);
   // sleep(waittime);
    pthread_mutex_unlock(&wsem);    
    printf("\nWriter %d is leaving",*ind);
    //sleep(30);

}

int main()
{
	
    int n1,n2,i;    
    printf("\nEnter the no of readers: ");
    scanf("%d",&n1);
    printf("\nEnter the no of writers: ");
    scanf("%d",&n2);
    for(i=0;i<n1;i++)
    {        int *p = (int*) malloc(sizeof(int));
                *p = i+1;
                pthread_create(&tidP[i],NULL,reader,p);  
                pthread_join(tidP[i],NULL);

	}
    for(i=0;i<n2;i++)
      { int *p = (int*) malloc(sizeof(int));
                *p = i+1;
                pthread_create(&tidC[i],NULL,writer,p);
                pthread_join(tidC[i],NULL);
		}  
		
		 
                
        
                
    //sleep(30);
    
    exit(0);
}