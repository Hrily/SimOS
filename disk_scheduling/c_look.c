//Ritwick Mishra, ritwix
#include<stdio.h>
#include<stdlib.h>//C-LOOK

int main()
{
    int n,q[100],i,j,k,seek=0,diff,head,prev,cyl;
    scanf("%d",&n);
    scanf("%d%d",&head,&prev);
    scanf("%d",&cyl);  
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
   
	if(prev<head){					// moving forward
    	for(j=i;j<n;j++){
    		diff=abs(q[j+1]-q[j]);
    		seek+=diff;
    		
		}
		
		for(j=0;j<i-1;j++){
			diff=abs(q[j+1]-q[j]);
			seek+=diff;
			
		}
		
	}
	else{						// moving backward
		for(j=i;j>0;j--){
			diff=abs(q[j]-q[j-1]);
			seek+=diff;
			
		}
	
		for(j=n;j>i+1;j--){
    		diff=abs(q[j]-q[j-1]);
    		seek+=diff;
    		
		}
		
	}
    
    
    printf("\nSeek time=%d\n",seek);
}
