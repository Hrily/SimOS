# include <stdio.h>
# include <pthread.h>
#include<stdlib.h>
# define BufferSize 10

void *Producer();
void *Consumer();
int flag;
int BufferIndex=0;
char *BUFFER;
int p,c;
pthread_cond_t Buffer_Not_Full=PTHREAD_COND_INITIALIZER;
pthread_cond_t Buffer_Not_Empty=PTHREAD_COND_INITIALIZER;
pthread_mutex_t mVar=PTHREAD_MUTEX_INITIALIZER;

int main()
{    
    pthread_t ptid,ctid;
    
    BUFFER=(char *) malloc(sizeof(char) * BufferSize);            
    int i,j;
    int n;
    int pr,co;
    // printf("Enter the number of producers and consumers : ");
    scanf("%d %d",&pr,&co);
    
    int prod[50]={0};
    int con[50]={0};

    int count;
    count= pr+co;
    int done=0;
    while(done!=count) 
   { i=rand()%3;
    if(i==1)
    { 
     if(p<pr&&prod[p]!=1)
     { flag=1;
	pthread_create(&ptid,NULL,Producer,NULL);
      pthread_join(ptid,NULL);
      if(flag==1)
      {
      prod[p]=1; p++; done++;
      }
     else  {printf("Sorry producer %d could not produce now\n",p+1);}
     }
    }
    else  if(i==2)
    { 
      if(c<co&&con[c]!=1)
      {   flag=1;
         pthread_create(&ctid,NULL,Consumer,NULL);
       pthread_join(ctid,NULL);
      if(flag==1)
       {  con[c]=1; c++;  done++;
       } 
      else
     { printf("Sorry consumer %d could not consume\n",c+1);  done++; c++;
      }
    }    
    }
 }
    return 0;
}

void *Producer()
{    int i,n;
    
    
    
        pthread_mutex_lock(&mVar);
        if(BufferIndex==BufferSize)
        {    flag=0;        
            pthread_cond_wait(&Buffer_Not_Full,&mVar);
        } 
        else
        {                       
        BUFFER[BufferIndex++]='@';
        printf("+%d\n",p+1,BufferIndex);
        pthread_mutex_unlock(&mVar);
        pthread_cond_signal(&Buffer_Not_Empty);        
      }
    
}

void *Consumer()
{   int i,n;
   
    
   
        pthread_mutex_lock(&mVar);
        if(BufferIndex==-1)
        {      flag=0;      
            pthread_cond_wait(&Buffer_Not_Empty,&mVar);
        }      
        else
        {          
         if(BufferIndex!=0)
         {
        printf("-%d\n",c+1,--BufferIndex);        
        pthread_mutex_unlock(&mVar);        
        pthread_cond_signal(&Buffer_Not_Full);                
        }
         else flag=0;
    }
}

