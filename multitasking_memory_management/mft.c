#include<stdio.h>
#include<stdlib.h>

struct block{
	int used, size;
	int isFree(){
		return used == 0;
	}
};

void mft(struct block blocks[], int sizes[],  int n){
	for(int i=0;i<n;i++){
		blocks[i].used = 0;
		blocks[i].size = sizes[i];
	}
}

void display(struct block blocks[], int n){
	int ifrag = 0, efrag = 0;
	//printf("#\tBlock Size\tUsed\tFree\n");
	for(int i=0;i<n;i++){
		int free = blocks[i].size - blocks[i].used;
		if(blocks[i].isFree())
			efrag += blocks[i].size;
		else
			ifrag += free;
		printf("%d %d %d<br>", i+1, blocks[i].size, blocks[i].used);
	}
	//printf("\nTotal Internal Fragmentation : %d\n", ifrag);
	//printf("Total External Fragmentation : %d\n", efrag);
	printf("\n");
	fflush(stdout);
}

int allocate(int size, struct block blocks[], int n, int fit){
	if(fit == 1){
		int i = 0;
		while(i<n){
			if(blocks[i].isFree() && blocks[i].size>=size)
				break;
			i++;
		}
		if(i<n){
			blocks[i].used = size;
			return 1;
		}
		return 0;
	}
	if(fit == 2){
		int mi = 0;
		for(int i=0;i<n;i++)
			if(blocks[i].isFree() && blocks[i].size>=size && blocks[i].size<blocks[mi].size)
				mi = i;
		if(mi<n){
			blocks[mi].used = size;
			return 1;
		}
		return 0;
	}
	if(fit == 3){
		int mi=0, i;
		for(int i=0;i<n;i++)
			if(blocks[i].isFree() && blocks[i].size>=size && blocks[i].size>blocks[mi].size)
				mi = i;
		if(mi<n){
			blocks[mi].used = size;
			return 1;
		}
		return 0;
	}
	return 0;
}

int main(){
	int n;
	//printf("Enter number of blocks : ");
	scanf("%d", &n);
	struct block blocks[n];
	int sizes[n];
	//printf("Enter sizes of %d blocks: \n", n);
	for(int i=0;i<n;i++)
		scanf("%d", &sizes[i]);
	mft(blocks, sizes, n);
	int allocation;
	//printf("Choose:\n\t1. First fit\n\t2. Best fit\n\t3. Worst fit\n");
	scanf("%d", &allocation);
	fflush(stdin);
	display(blocks, n);
	int c = 10;
	while(c!=0){
		//printf("Choose : \n\t1. Add Process\n\t2. Free\n\t3. Display\n\t0. Exit\n");
		scanf("%d", &c);
		if(c==1){
			int s;
			//printf("Enter process size : ");
			scanf("%d", &s);
			if(allocate(s, blocks, n, allocation))
				display(blocks, n);
			else
				printf("~Process allocation failed\n");
			fflush(stdout);
		}else if(c==2){
			int i;
			//printf("Enter block number : ");
			scanf("%d", &i);
			i--;
			blocks[i].used = 0;
			display(blocks, n);
		}
		else if(c==3)
			display(blocks, n);
		else if(c!=0)
			printf("Invalid input\n");
	}
	return 0;
}
