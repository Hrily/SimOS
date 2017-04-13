#include<stdio.h>
#include<stdlib.h>
struct block{
		int allocate;
		int size;
		int id;
		int pid;
};
void main()
{
	
	int mem,os,i,n,nb,frag,j,k,ch,ch1,flag,index,flag1=0;	//b-blocks,s-size
	scanf("%d",&nb);//cin N-total no of partitions
	struct block b[nb];
	struct block temp;
	scanf("%d",&mem);//cin S	//available memory for process allocation
	int p[100];
	for(i=0;i<nb;++i)
	{
		printf("\nEnter size of block %d :",i+1);
		scanf("%d",&b[i].size);
		b[i].allocate=0;
		b[i].id=i+1;
		b[i].pid=-1;
	}
	struct block bc[nb];
	for(i=0;i<nb;++i)
	{
		bc[i].size=b[i].size;
		bc[i].allocate=b[i].allocate;
		bc[i].id=b[i].id;
		bc[i].pid=b[i].pid;
	}
	i=0;
	while(1)
	{

		scanf("%d",&ch);
		switch(ch)
		{
			case 1: //fixed
					
					while(1)
					{
						scanf("%d",&ch1);
						switch(ch1)
					{

						case 1: 
								if(i==nb)
									{
										printf("\n0\n");
										break;
									}
								scanf("%d",&p[i]);
								flag=0;
										for(j=0;j<nb;++j)//arranges based on id
										{
											for(k=0;k<nb-1;++k)
											{
												if(bc[k].id>bc[k+1].id)
												{
													temp=bc[k];
													bc[k]=bc[k+1];
													bc[k+1]=temp;
												}
											}
										}
										for(j=0;j<nb;++j)
										{
											if(bc[j].allocate!=1&&bc[j].size>=p[i])
											{
												bc[j].allocate=1;
												bc[j].pid=i;
												flag=1;
												
												break;
											}

										}
										if(flag==0)
											printf("\n0");
										else
											printf("\n1");
										

						break;
						case 2: scanf("%d",&index);
								index--;
								for(k=0;k<nb;++k)
								{
									if(bc[k].pid==index)
										bc[k].allocate=0;
								}

						break;
						case 3:for(k=0;k<nb;++k)
								{
									printf("%d\t%d\t%d",bc[k].id,bc[k].size,bc[k].allocate);
									printf("\n");
								}
						break;
						case 0: flag1=1;break;
						
					}
					++i;
					if(flag1==1)
						break;
				}
			break;
			case 2:	//best
			while(1)
			{
				scanf("%d",&ch1);
			switch(ch1)
					{
						case 1: scanf("%d",&ch1);
								if(i==nb){
										printf("\n0\n");
										break;
									}

								scanf("%d",&p[i]);
								flag=0;
										for(j=0;j<nb;++j)
										{
											for(k=0;k<nb-1;++k)
											{
												if(bc[k].size>bc[k+1].size)
												{
													temp=bc[k];
													bc[k]=bc[k+1];
													bc[k+1]=temp;
												}
											}
										}
										for(j=0;j<nb;++j)
										{
											if(bc[j].allocate!=1&&bc[j].size>=p[i])
											{
												bc[j].allocate=1;
												bc[j].pid=i;
												flag=1;
												
												break;
											}

										}
										if(flag==0)
											printf("\n0");
										else
											printf("\n1");
										

						break;
						case 2: scanf("%d",&index);
								index--;
								for(k=0;k<nb;++k)
								{
									if(bc[k].pid==index)
										bc[k].allocate=0;
								}

						break;
						case 3:for(k=0;k<nb;++k)
								{
									printf("%d\t%d\t%d",bc[k].id,bc[k].size,bc[k].allocate);
									printf("\n");
								}
						break;
						case 0: flag1=1; break;

					}
					if(flag1==1)
						break;
					++i;
				}
			break;
			case 3: //worst
			while(1)
			{scanf("%d",&ch1);
			switch(ch1)
					{
						case 1: scanf("%d",&ch1);
								if(i==nb){
										printf("\n0\n");
										break;
									}
								scanf("%d",&p[i]);
								flag=0;
										for(j=0;j<nb;++j)
										{
											for(k=0;k<nb-1;++k)
											{
												if(bc[k].size<bc[k+1].size)
												{
													temp=bc[k];
													bc[k]=bc[k+1];
													bc[k+1]=temp;
												}
											}
										}
										for(j=0;j<nb;++j)
										{
											if(bc[j].allocate!=1&&bc[j].size>=p[i])
											{
												bc[j].allocate=1;
												bc[j].pid=i;
												flag=1;
												
												break;
											}

										}
										if(flag==0)
											printf("\n0");
										else
											printf("\n1");
										

						break;
						case 2: scanf("%d",&index);
								index--;
								for(k=0;k<nb;++k)
								{
									if(bc[k].pid==index)
										bc[k].allocate=0;
								}

						break;
						case 3:for(k=0;k<nb;++k)
								{
									printf("%d\t%d\t%d",bc[k].id,bc[k].size,bc[k].allocate);
									printf("\n");
								}
						break;
						case 0: flag1=1; break;
					}
					if(flag1==1)
						break;
					++i;
			}		
			break;
		}
	}
}
