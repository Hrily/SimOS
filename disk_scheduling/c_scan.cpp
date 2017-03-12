//Abhilash Sanap 15CO241
#include<stdio.h>
#include<stdlib.h>//SCAN

int main()
{
    int* q; //pointer to array that stores requests
	int tot_req,header,previous,begin,end,i,seek_t=0,diff,j,k; // seek_t stores seek time
		printf("Enter total no of requests in queue\n");
		scanf("%d",&tot_req);
		
		printf("Enter header and previous request\n");
		scanf("%d%d",&header,&previous);
		
		printf("Enter begin and end of cylinders\n");
    	scanf("%d%d",&begin,&end);
    
		q=(int*)malloc((tot_req+3)*sizeof(int)); //Allocating memory for request array
	
		printf("Enter Requests:\n");
		
		for(i=1;i<=tot_req;i++) //reading requests
			scanf("%d",&q[i]);
	
    q[0]=header;
    q[tot_req+1]=begin;
    q[tot_req+2]=end;
    
  	
    for(i=0;i<tot_req+2;i++) // Bubble Sort the disk requests
    for(j=0;j<tot_req+2-i;j++)
    {
       if(q[j]>q[j+1])
       {
         k=q[j];
         q[j]=q[j+1];
         q[j+1]=k;
       }
    }
     
   	
    for(i=0;i<tot_req+1;i++){
    	if(q[i]==header)
    		break;
	}
	
	if(previous<header){
		for(j=i;j<=tot_req+2;j++)
			printf("%d\t",q[j]);
		for(j=0;j<i;j++)
			printf("%d\t",q[j]);
    	for(j=i;j<tot_req+2;j++){
    		diff=abs(q[j+1]-q[j]);
    		seek_t+=diff;
    		
		}
		for(j=1;j<i;j++){
			diff=abs(q[j]-q[j-1]);
			seek_t+=diff;
		
		}
	}
	else{
		for(j=i;j>=0;j--)
			printf("%d\t",q[j]);
		for(j=tot_req+2;j>i;j--)
				printf("%d\t",q[j]);
		for(j=i;j>0;j--){
			diff=abs(q[j]-q[j-1]);
			seek_t+=diff;
		}
		for(j=tot_req+1;j>i;j--){
    		diff=abs(q[j+1]-q[j]);
    		seek_t+=diff;
    		
		}
	}
    
    
    printf("\nTotal head movement=%d\n",seek_t);
}
