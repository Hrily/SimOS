#include<stdio.h>
#include<stdlib.h>
int main()
{
        int i,j,n,a[50],frame[10],no,k,avail,count=0;
        int t=0,m=0,jl;
        float fRatios[100];
        float hr,fra;
       printf("Enter the number of frames: ");
        scanf("%d",&no);
        printf("Enter the number of pages: ");
        scanf("%d",&n);
        printf("Enter the page reference string: ");
        for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
        for(i=0;i<no;i++)
        frame[i]= -1;
        jl=0;
    j=0;
    printf("\tRef string\t page frames\n");
        for(i=1;i<=n;i++)
    	{
    		//t=t+1;
        printf("%d\t\t",a[i]);
        avail=0;
        for(k=0;k<no;k++)
                if(frame[k]==a[i])
                {
                        for(k=0;k<no;k++)
                           printf("%d\t",frame[k]);
                                avail=1;
                }
                if (avail==0)
                {

                                frame[j]=a[i];
                                j=(j+1)%no;
                                printf("\nF\n");
                                count++;
                                
                                //m=m+1;
                                
                               for(k=0;k<no;k++)
                                        printf("%d\t",frame[k]);
                }
                printf("\n");
		
	
	printf("\n\nCount   %d\t Total  %d\t Ratio %f\n\n",count,i,(count*(1.0)/i*(1.0)));

   	}
        fra=(float)count/n;
        hr=1-fra;
        printf("\nPage fault is %d\n",count);
        printf("%f\n",hr);
        printf("Fault ratio is %f\n\n",fra);
        
        for(i=0;i<n;i++)
        {
        	printf("%d\t\t",fRatios[i]);
		}
		printf("\n\n");
        return 0;
}
