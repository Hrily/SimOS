#include<stdio.h>
#include<stdlib.h>
int main()
{
        int i,j,n,a[50],frame[10],no,k,avail,count=0;
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
    j=0;
    printf("\tRef string\t page frames\n");
        for(i=1;i<=n;i++)
    	{
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
                                count++;
                                for(k=0;k<no;k++)
                                        printf("%d\t",frame[k]);
                }
                printf("\n");

   	}
        fra=(float)count/n;
        hr=1-fra;
       // printf("\nPage fault is %d\n",count);
        printf("Hit ratio is %f\n",hr);
      //  printf("Fault ratio is %f\n",fra);
        return 0;
}
