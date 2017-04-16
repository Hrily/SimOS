#include<stdio.h>

int get_max_ind(int a[], int s, int n, int q){
	int mi = -1;
	for(int i=s;i<n;i++)
		if(a[i] == q)
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
	int mm[n], ut[n], t = 0, nhit = 0;
	for(int i=0;i<n;i++) mm[i] = ut[i] = -1;
	int q;
	//printf("Enter number of page requests : ");
	scanf("%d", &q);
	int pr[q];
	//printf("Enter %d pages : \n", q);
	for(int i=0;i<q;i++)
		scanf("%d", &pr[i]);
	for(int i=0;i<q;i++){
		int s = search(mm, n, pr[i]);
		if(s>=0){
			printf("1 ");
			nhit++;
		}else{
			printf("0 ");
			int mt = -1, mti = -1;
			if(i<n){
				mm[i] = pr[i];
				//printf("Added Page #%d\n", pr[i]);
				continue;
			}
			for(int j=0;j<n;j++){
				int pn = mm[j];
				int mi = get_max_ind(pr, i, q, pn);
				if(mi<0){
					mti = j;
					break;
				}else
					if(mti<mi){
						mt = mi;
						mti = j;
					}
			}
			mti = (mti<0)? 0: mti;
			//printf("Replacing Page #%d with #%d\n", mm[mti], pr[i]);
			mm[mti] = pr[i];
		}
	}
	printf("%f\n", (float)100.0*nhit/q);
	return 0;
}
