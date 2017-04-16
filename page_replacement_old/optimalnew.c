#include<stdio.h>
#include<stdlib.h>
int main()
{
    int fr, p, frames[10], pages[30], temp[10], f1, f2, f3, i, j, k, pos,max, faults=0;
    float hr,fra;
    printf("Enter number of frames: ");
    scanf("%d", &fr);
    printf("Enter number of pages: ");
    scanf("%d", &p);
    printf("Enter page reference string: ");
    for(i=0;i<p;++i)
    {
        scanf("%d", &pages[i]);
    }
    for(i=0;i<fr;++i)
    {
        frames[i] = -1;
    }
    for(i=0;i<p;++i)
    {
        f1=f2=0;
        for(j=0;j<fr;++j)
        {
            if(frames[j] == pages[i])
            {
                   f1=f2= 1;
                   break;
            }
        }
        if(f1 == 0){
            for(j=0;j<fr;++j)
            {
                if(frames[j] == -1)
                {
                    faults++;
                    frames[j] = pages[i];
                    f2=1;
                    break;
                }
            }
        }
        if(f2==0)
        {
            f3=0;
            for(j=0;j<fr;++j)
            {
                temp[j] = -1;
                for(k =i+1;k<p;++k)
                {
                    if(frames[j]== pages[k]){
                        temp[j]=k;
                        break;
                    }
                }
            }
            for(j=0;j<fr;++j){
                if(temp[j] == -1){
                    pos = j;
                    f3 = 1;
                    break;
                }
            }

            if(f3 ==0)
            {
                max = temp[0];
                pos = 0;
                for(j=1;j<fr;++j)
                {
                    if(temp[j]>max)
                    {
                        max=temp[j];
                        pos=j;
                    }
                }
            }

            frames[pos]=pages[i];
            faults++;
        }
        printf("\n");
        for(j = 0; j<fr;++j)
        {
            printf("%d\t", frames[j]);
        	}
        	printf("\n\n\t\t%f\t\n\n",(faults*1.0)/((i+1)*1.0));
    	}
	fra=(float)faults/p;
        hr=1-fra;
        printf("\nPage fault is %d\n",faults);
        printf("%f\n",hr);
        printf("Fault ratio is %f\n",fra);
	return 0;
}

