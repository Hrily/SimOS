//Abhilash Sanap 15CO241
#include<stdio.h>
#include<stdlib.h>
#include<math.h>// FCFS
 main(){
	int* a; //pointer to array that stores requests
	int tot_req,header,previous,cyl,i,seek_t=0; // st stores seek time
		
		scanf("%d",&tot_req);
		scanf("%d%d",&header,&previous);
    	scanf("%d",&cyl);
    
		a=(int*)malloc(tot_req*sizeof(int)); //Allocating memory for request array
		
		previous=header; // previous stores last served request but in FCFS it is initialised to header
		for(i=0;i<tot_req;i++){ //reading requests
			scanf("%d",&a[i]);
			
				seek_t += abs(a[i]-previous);
				previous=a[i];
				
	}
	for(i=0;i<tot_req;i++)
		printf("%d\t",a[i]);
	printf("\nSeek time: %d\n",seek_t);
}
