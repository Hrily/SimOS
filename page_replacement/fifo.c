#include<stdio.h>

int get_min(int a[], int n){
	int mi = 0;
	for(int i=1;i<n;i++)
		if(a[i]<a[mi])
			mi = i;
	return mi;
}

int search(int a[], int n, int q){
	for(int i=0;i<n;i++)
		if(a[i] == q)
			return i;
	return -1;
}

int main(){
	int n;
	//printf("Enter number of frames : ");
	scanf("%d", &n);
	int mm[n], ct[n], t = 0, nhit = 0;
	for(int i=0;i<n;i++) mm[i] = ct[i] = -1;
	int q;
	//printf("Enter number of page requests : ");
	scanf("%d", &q);
	//printf("Enter %d pages : \n", q);
	for(int i=0;i<q;i++){
		int p;
		scanf("%d", &p);
		int s = search(mm, n, p);
		if(s>=0){
			printf("1 ");
			nhit++;
		}else{
			printf("0 ");
			int r = get_min(ct, n);
			//if(ct[r]<0)
				//printf("Adding Page #%d\n", p);
			//else
				//printf("Replacing Page #%d with #%d\n", mm[r], p);
			ct[r] = t++;
			mm[r] = p;
		}
	}
	printf("%f\n", (float)100.0*nhit/q);
	return 0;
}
