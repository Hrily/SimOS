//Ritwick Mishra , ritwix
#include<stdio.h>
#include<stdlib.h>//SSTF
int n=0,q[100]={0}; //array to store request  and  its size
void del(int i){	//for queue operations
	i++;
	while(i<=n){
		q[i-1]=q[i];
		i++;
	}
	n--;
}

int main()
{
    int i,j,k,seek=0,diff,head,previous,cyl;
	scanf("%d",&n);
    scanf("%d%d",&head, &previous);
    q[0]=head;// put head in front of array
    scanf("%d",&cyl);

	for(i=1;i<=n;i++){
        
        scanf("%d",&q[i]);
    }
	//sort array by bubble sort 
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
	// i is initially set to index of head request
	
			// printing head
	int cnt=n+1;		 // no. of requests in list including present diskhead position
	int o,flag=0;
	while(cnt!=1){
		if(i==n){				// boundary condition 1
			
			diff=abs(q[i-1]-q[i]);
			seek+=diff;
			
			del(i);
		}
		else if (i==0){ 		//boundary condition 2
			diff=abs(q[i+1]-q[i]);
			seek+=diff;
			
			del(i);
		}
		else{
		if(abs(q[i+1]-q[i]) < abs(q[i-1]-q[i])){
			flag=0;   								//nearest block to right is selected
			
		}
		else flag=1;								//nearest block to left is selected
		if(flag==0){
			diff=abs(q[i+1]-q[i]);
			o=i+1;	
		}
		else {
			diff=abs(q[i-1]-q[i]);
			o=i-1;
		}
		//o is the index of selected request
		seek+=diff;
		
	
		del(i);				//removes request from list and shifts all requests to its right 1 step to the left
		if(flag)
			i=o;		// updating i to selected disk
	}
		
		
		cnt--;
		
	}
    	
    
    printf("\nSeek Time: %d\n",seek);
    return 0;
}
