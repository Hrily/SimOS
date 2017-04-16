#include<stdio.h>

#include<math.h>
struct process
{
 float t,p,d,rem;
 int done,pno;
 int multiple;
}pr[25];
int n;
int findmaxdeadline()
{ int i;
  int max=pr[0].d;
  int m=0; 
  for(i=0;i<n;i++)
  {
   if(pr[i].d>max)
   {
    max=pr[i].d;
    m=i;
   }
  }
 return max;
}
int isanydeadline(int t)
{ int i;
 for(i=0;i<n;i++)
 {
  if(pr[i].d==t) 
   return 1;
 }
 return 0;
}

int findwhosedeadline(int t)
{int i;
 for(i=0;i<n;i++)
 {
  if(pr[i].d==t)
   return i;
  }
}
void sortbyexecutiontime()
{
 int i,j;
  struct process temp;
 for(i=0;i<n-1;i++)
 {  
   for(j=0;j<n-1;j++)
   {
    if(pr[j].p>pr[j+1].p)
      {
       temp=pr[j];
	pr[j]=pr[j+1];
	pr[j+1]=temp;
      }
   }
  }
 }

int allaredone()
{int i;
 for(i=0;i<n;i++)
 {
  if(pr[i].done==0)
   return 0;
 }
 return 1;
}
void main()
{
 
  int i;
  float ut,u,x,y;
  
  
  int time;
  printf("\n Enter Number of Processes :: ");
  scanf("%d",&n);

  for(i=0;i<n;i++)
  {
   pr[i].pno=i+1;
   printf("\n Enter Execution Time for P%d ::",(i+1));
   scanf("%f",&pr[i].t);
   printf("Enter Period for P%d ::",(i+1));
   scanf("%f",&pr[i].p);
   pr[i].done=0;
   pr[i].d=pr[i].p;
   pr[i].rem=pr[i].t;
   pr[i].multiple=1;
  }
  //calculate the utilization
  for(i=0;i<n;i++)
  {
   x=pr[i].t/pr[i].p;
   ut+=x;
  }

  //calculate value of U
  y=(float)n;
  y=y*((pow(2.0,1/y))-1);
  u=y;
   
  int maxd=findmaxdeadline();
  printf("\nThe threshold is %f\nThe utilization is %f\n",u,ut);
  if(ut<u)
  {
 printf("\n As %f < %f ,",ut,u);
 printf("\n The System is surely Schedulable by rate monotonic scheduling\n\n");
  sortbyexecutiontime();
  int prev=0;
 int ongoing=0;
  time=0;
  int flag=0;
  while(!allaredone())
  { 
    if(pr[ongoing].done==0&&!isanydeadline(time))
    {
     printf("%d->P%d\n",time,pr[ongoing].pno);
     pr[ongoing].rem--;
     time++;
     if(pr[ongoing].rem==0)
     {
	pr[ongoing].done=1;
	printf("\nP%d done\n",pr[ongoing].pno);
	pr[ongoing].rem=pr[ongoing].t;
	pr[ongoing].d=pr[ongoing].multiple*pr[ongoing].p;
		pr[ongoing].multiple++;
     }
    }
    else if(pr[ongoing].done==1)
	 {
	  if(flag==1)
	   ongoing=prev;
	  else ongoing=(ongoing+1)%n;
	  printf("%d->P%d\n",time,pr[ongoing].pno);
	  pr[ongoing].rem--;
     	  time++;
     	  if(pr[ongoing].rem==0)
     	  {
		pr[ongoing].done=1;
		printf("\nP%d done\n",pr[ongoing].pno);
		pr[ongoing].rem=pr[ongoing].t;
		pr[ongoing].d=pr[ongoing].multiple*pr[ongoing].p;
		pr[ongoing].multiple++;
     	  }
         }
	 else if(pr[ongoing].done==0&&isanydeadline(time))
	      { flag=1;
		prev=ongoing;
		ongoing=findwhosedeadline(time);
		printf("\nPreempted by P%d\n\n",pr[ongoing].pno);
		printf("%d->P%d\n",time,pr[ongoing].pno);
		pr[ongoing].done=0;
     		pr[ongoing].rem--;
     		time++;
     		if(pr[ongoing].rem==0)
     		{
		 pr[ongoing].done=1;
		 printf("\nP%d done\n",pr[ongoing].pno);
		 pr[ongoing].rem=pr[ongoing].t;
		 pr[ongoing].d=pr[ongoing].multiple*pr[ongoing].p;
		pr[ongoing].multiple++;
     		}
  	      }
 }
}
 else
 printf("\n Not Sure.....");
 
}

