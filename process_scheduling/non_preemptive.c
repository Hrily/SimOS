//Manali Gala 15co214


#include<stdio.h>
//non preemtive prioirty scheduling
////Doing with the assumption that higher value means higher priority
struct task
{
int no;
int pri;
int arrival;
int burst;
int st;
int tat;
int ct;
int wt;
}arr[20],heap[20],final[20];
int n,heapsize=0,findex=0,hindex=0;

void bubblesort() 			//sorting acc to arrival time
{
int i,j;
for(i=0;i<n-1;i++)//Gives the number of iterations to be performed
{
for(j=0;j<=(n-2-i);j++)
{
struct task temp;
if(arr[j].arrival>arr[j+1].arrival)
{
temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}
}


void insert(struct task a)		//Adding in queue based on priority order
{
heap[heapsize]=a;
heapsize++;
int j;
for(j=hindex+1;j<=(heapsize-1);j++)
{
int p;
for(p=j-1;p>=hindex;p--)
{
if(heap[p].pri>heap[j].pri)
break;
}

struct task num=heap[j];
int k;
for(k=j;k>=p+2;k--)
heap[k]=heap[k-1];
heap[p+1]=num;

}
}


void main()
{
scanf("%d",&n);
int i;
for(i=0;i<n;i++)
scanf("%d %d %d %d",&arr[i].no,&arr[i].arrival,&arr[i].burst,&arr[i].pri);
bubblesort();
//presently the heap is empty
int time=0;
int k=0;//Shows from where the array is valid



while(findex<n)
{
while(k<n&&arr[k].arrival<=time)
insert(arr[k]),k++;
//Now k shows the rest part of the array
if(heapsize==0)
{time++;
continue;
}
else
{
final[findex]=heap[hindex];
findex++,hindex++;
final[findex-1].st=time;
time=time+final[findex-1].burst;
final[findex-1].ct=time;
final[findex-1].tat=final[findex-1].ct-final[findex-1].arrival;
final[findex-1].wt=final[findex-1].tat-final[findex-1].burst;

}

}




float totaltat=0,totalwt=0;

for(i=0;i<n;i++)
totaltat+=final[i].tat,totalwt+=final[i].wt;

float avgtat,avgwt;
avgtat=totaltat/n;
avgwt=totalwt/n;

//printf("NO\tST\tCT\tTAT\tWT\n");
for(i=0;i<n;i++)
{
printf("%d %d %d %d %d",final[i].no,final[i].st,final[i].ct,final[i].tat,final[i].wt);
printf("\n");
}

printf("Average TT: %f\nAverage WT: %f\n",avgtat,avgwt);
}
