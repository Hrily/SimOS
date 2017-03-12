//Abhilash Sanap 15CO241
#include<stdio.h>
#include<stdlib.h>//SCAN

int main()
{
    int* q; //pointer to array that stores requests
	int tot_req,header,previous,cyl,i,seek_t=0,diff,j,k; // seek_t stores seek time
	
		scanf("%d",&tot_req);
		scanf("%d%d",&header,&previous);
    	scanf("%d",&cyl);
    
		q=(int*)malloc((tot_req+3)*sizeof(int)); //Allocating memory for request array
	
		for(i=1;i<=tot_req;i++) //reading requests
			scanf("%d",&q[i]);
	
    q[0]=header;
    q[tot_req+1]=0;
    q[tot_req+2]=cyl-1;
    
  	
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
