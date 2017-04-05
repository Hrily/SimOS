#include<stdio.h>
#include<stdlib.h>

int mutex[20];

int main()
{
        int n,i,ch,j;
       // printf("Enter the number of philosophers\n");
        scanf("%d", &n);

        for(i=0;i<n;i++)
        mutex[i]=1;

       /* printf("Initial State is: \n");
        for(i=0;i<n;i++)
        printf("Philosopher %d is thinking\n",i);*/
        //printf("enter the number of rounds\n");
        scanf("%d",&ch);
                
        for(j=0;j<ch;j++)
        {
         int random=rand()%n;
         int r=rand()%2;

         mutex[random]=r;
         for(i=(random+1)%n;i!=random;i=(i+1)%n)
        {
         r=rand()%2;
         if(r==0)
         {      if(i==0)
                {
                        if(mutex[n-1]==1)
                        mutex[i]=0;
                        else mutex[i]=1;
                }
                else if(mutex[(i-1)%n]==1)
                   mutex[i]=0;
                else mutex[i]=1;
         }
         else mutex[i]=1;
        }
        r=rand()%2;
        i=(random-1)%n;
        if(i<0) i+=n;
        if(r==0)
        {
          if(i==0)
          {
                if(mutex[n-1]==1 && mutex[(i+1)%n]==1)
                mutex[i]=0;
                else
                mutex[i]=1;
          }
          else if(mutex[(i-1)%n]==1 && mutex[(i+1)%n]==1)
                mutex[i]=0;
          else mutex[i]=1;
        }
        else mutex[i]=1;
        //printf("Next Round is\n");
        for(i=0;i<n;i++)
        {
                if(mutex[i]==1)
                {
                //printf("Philosopher %d is thinking\n",i);
                printf("%d ",0);
                }
                else
                {
                //printf("Philosopher %d is eating\n",i);
                printf("%d ",1);
                }
                
        }
        printf("\n");

        }

}

