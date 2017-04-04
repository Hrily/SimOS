
//Ritwick Mishra, ritwix
#include<stdio.h>
#include<stdlib.h>//SCAN

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
    q[n+1]=0;
    q[n+2]=cyl-1;
    
  
   	//sort the array
	   	
    for(i=0;i<n+2;i++)
    for(j=0;j<n+2-i;j++)
    {
       if(q[j]>q[j+1])
       {
         k=q[j];
         q[j]=q[j+1];
         q[j+1]=k;
       }
    }
   
  
    for(i=0;i<=n+2;i++){
    	if(q[i]==head)
    		break;
	}
	//i is initially set to index of head request
	printf("%d ",q[i]);
	if(prev<head){
					// move forward
    	if(q[1]!=head){
    		for(j=i+1; j<n+2; j++){
    			printf("%d ",q[j]);
			}
			
		
			for(j=i;j<n+2;j++){
    			diff=abs(q[j+1]-q[j]);
    			seek+=diff;
    			
    		}
			seek+=q[j]-q[i-1];
			printf("%d ",cyl); 	
					// move backward 
			for(j=i-1; j>=1; j--){
				printf("%d ",q[j]);
			}
			for(j=i-1; j>=2; j--){
			
					diff=abs(q[j]-q[j-1]);
					
					seek+=diff;
				}
				
			}
			
		
		else{
			for(j=i; j<n+2; j++){
				diff=abs(q[j+1]-q[j]);
				seek+=diff;
				if(j!=n+1){
					printf("%d ",q[j+1]);
				}
			}
		}
}
	
	else{
		if(q[n+1]!=head){
			for(j=i-1; j>=1; j--){
				printf("%d ",q[j]);
			}						
			for(j=i;j>0;j--){
				diff=abs(q[j]-q[j-1]);
				seek+=diff;
				
			}
			seek+=q[i+1]-q[j];
			printf("0 ");	
			for(j=i+1; j<=n+1; j++){
				printf("%d ",q[j]);
			}			
			for(j=i+1; j<n+1 ; j++){
    			diff=abs(q[j+1]-q[j]);
    			seek+=diff;
    			
		}
		
	}
	else{
		for(j=i; j>0; j--){
			diff=abs(q[j]-q[j-1]);
			seek+=diff;
			if(j!=1){
				printf("%d ",q[j-1]);
			}
		}
	}
	}
    
    printf("\nSeek Time: %d\n",seek);
}
