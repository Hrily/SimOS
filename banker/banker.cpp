//need avail allo max
#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
int need[20][10],avail[10],allo[20][10];
int maxi[20][10];
int n,r;// n=no of processes r=no of resources
int checkp(int p){
	for(int i=0;i<r;i++){
		if(need[p][i]>avail[i])
			return 0;
	}
	return 1;
}
void safety(){
	int i,j;
	int f[10]={0};
	int key=1;
	vector<int> v;
	while(key){
			int flag=0;
		for(i=0;i<n;i++){
			if(f[i]==0 && checkp(i))
			{
				flag=1;	
				v.push_back(i);
				f[i]=1;
				break;
			} 
		}
		if(flag==1){
			for(int k=0;k<r;k++)
					avail[k]+=allo[i][k];
			f[i]=1;
			}
		else{
			int m=0;
			for(i=0;i<n;i++){
				if(f[i]==0){
					m=1;
					break;	
			}
			}
			if(m==1){
				key=0;
			}
			else
				key=0;
			break;
		}
	}
	if(v.size()==n){
		vector<int>::iterator it;
		cout<<"Safe Sequence:";
		for(it=v.begin();it!=v.end();it++)
			cout<<*it<<" ";
	}
	else
		cout<<"Deadlock\n";

		return;
}
int main(){
	int i,j,a1,a2,a3;
	int ch,dp=1,f;
	int req[10];
	while(dp){
		cin>>ch;
	switch(ch){
			case 1:
			
		cin>>n>>r;
		for(i=0;i<n;i++)
			for(j=0;j<r;j++)
			scanf("%d",&allo[i][j]);

		for(i=0;i<n;i++)
			for(j=0;j<r;j++)
			cin>>maxi[i][j];

		for(j=0;j<r;j++)
		scanf("%d",&avail[j]);

		//Calculating need	
	for(i=0;i<n;i++){
		for(j=0;j<r;j++){
			need[i][j]=maxi[i][j]-allo[i][j];
						}
	

	safety();
			break;
			case 2:
			
	cin>>n>>r;
	
		for(i=0;i<n;i++)
			for(j=0;j<r;j++)
			scanf("%d",&allo[i][j]);

	
		for(i=0;i<n;i++)
			for(j=0;j<r;j++)
			cin>>maxi[i][j];

			for(j=0;j<r;j++)
		scanf("%d",&avail[j]);
		//Calculating need	
		for(i=0;i<n;i++){
		for(j=0;j<r;j++){
			need[i][j]=maxi[i][j]-allo[i][j];
						}
	
	
		scanf("%d",&i);
		 f=1;
		for(int k=0;k<r;k++){
			cin>>req[i];
			if(req[k]>avail[k] || req[i]>need[i][k]){
				cout<<"Request can't be granted\n";
				f=0;
				break;
			}
			avail[i]-=req[i];
			need[i][k]-=req[i];
			allo[i][k]+=req[i];
		}


			if(f==1)
			safety();

			break;
		case 3:
			dp=0;
			
	}
}

	
	return 0;
}
