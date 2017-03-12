//Ritwick Mishra, ritwix
#include<stdio.h>
#include<stdlib.h>//C-LOOK

int main()
{
    int n,q[100],i,j,k,seek=0,diff,head,prev,begin,end;

    //printf("Enter total no. of requests in queue\n");
    scanf("%d",&n);
    
    //printf("Enter header and previous request\n");
    scanf("%d%d",&head,&prev);
    //printf("Enter begin and end\n");
    scanf("%d%d",&begin,&end);  
	//printf("Enter %d requests:\n", n);
	for(i=1;i<n+1;i++){
      
        scanf("%d",&q[i]);
    }
	
    q[0]=head;
   //sort the array
    for(i=0;i<n;i++)
    for(j=0;j<n-i;j++)
    {
       if(q[j]>q[j+1])
       {
         k=q[j];
         q[j]=q[j+1];
         q[j+1]=k;
       }
    }
    
   
    for(i=0;i<n+1;i++){
    	if(q[i]==head)
    		break;
	}
	//i is initially set to index of head request
    printf("%d\t",q[i]);
	if(prev<head){					// moving forward
    	for(j=i;j<n;j++){
    		diff=abs(q[j+1]-q[j]);
    		seek+=diff;
    		printf("%d\t",q[j+1]);
		}
		
		for(j=0;j<i-1;j++){
			diff=abs(q[j+1]-q[j]);
			seek+=diff;
			printf("%d\t",q[j]);
		}
		printf("%d",q[j]);
	}
	else{						// moving backward
		for(j=i;j>0;j--){
			diff=abs(q[j]-q[j-1]);
			seek+=diff;
			printf("%d\t",q[j-1]);
		}
	
		for(j=n;j>i+1;j--){
    		diff=abs(q[j]-q[j-1]);
    		seek+=diff;
    		printf("%d\t",q[j]);
		}
		printf("%d",q[j]);
	}
    
    
    printf("\n%d\n",seek);
}
