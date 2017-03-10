//Abhilash Sanap 15CO241
#include<stdio.h>
#include<stdlib.h>// FCFS
 main(){
	int* a; //pointer to array that stores requests
	int tot_req,header,previous,begin,end,i,seek_t=0; // st stores seek time
		printf("Enter total no of requests in queue\n");
		scanf("%d",&tot_req);
		
		printf("Enter header and previous request\n");
		scanf("%d%d",&header,&previous);
		
		printf("Enter begin and end of cylinders\n");
    	scanf("%d%d",&begin,&end);
    
		a=(int*)malloc(tot_req*sizeof(int)); //Allocating memory for request array
		
		previous=header; // previous stores last served request but in FCFS it is initialised to header
		printf("Enter Requests:\n");
		for(i=0;i<tot_req;i++){ //reading requests
			scanf("%d",&a[i]);
			
			if(previous>a[i]){		 // current request is greater than previous
				seek_t += previous-a[i];
				printf("%d\t",a[i]);
			}
				
			
			else{					// current request is smaller than previous
				seek_t += a[i]-previous;
				printf("%d\t",a[i]);
			previous=a[i];
		}
	
}
	printf("\nsTotal seek time=%d",seek_t);
}
