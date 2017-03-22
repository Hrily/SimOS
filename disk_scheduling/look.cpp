//Abhilash Sanap 15CO241
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int* q; //pointer to array that stores requests
	int tot_req,header,previous,cyl,seek_t=0,i,j,k,diff; // seek_t stores seek time
		scanf("%d",&tot_req);
		scanf("%d%d",&header,&previous);
    	scanf("%d",&cyl);
    
		q=(int*)malloc((tot_req+1)*sizeof(int)); //Allocating memory for request array
		
		for(i=1;i<=tot_req;i++)
			scanf("%d",&q[i]);
			
		q[0]=header;
			
    for(i=0;i<tot_req;i++) 
    for(j=0;j<tot_req-i;j++)
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
    	for(j=i+1;j<=tot_req;j++)
			printf("%d\t",q[j]);
			
		for(j=i-1;j>=0;j--)
			printf("%d\t",q[j]);
			
    	for(j=i;j<tot_req;j++){
    		diff=abs(q[j+1]-q[j]);
    		seek_t+=diff;
    		
		}
		q[i]=q[tot_req];
		for(j=i;j>0;j--){
			diff=abs(q[j]-q[j-1]);
			seek_t+=diff;
		
		}
		q[i]=header;
	}
	else{
		for(j=i-1;j>=0;j--)
			printf("%d\t",q[j]);
			
		for(j=i+1;j<=tot_req;j++)
				printf("%d\t",q[j]);
				
		for(j=i;j>0;j--){
			diff=abs(q[j]-q[j-1]);
			seek_t+=diff;
		}
		q[i]=q[0];
		for(j=i;j<tot_req;j++){
    		diff=abs(q[j+1]-q[j]);
    		seek_t+=diff;
    				}
		q[i]=header;
	}
    
    
    printf("\nSeek time=%d\n",seek_t);
}
