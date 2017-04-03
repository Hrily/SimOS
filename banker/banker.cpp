//need avail allo max
#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
int need[20][10],avail[10],avail1[10],allo[20][10];
int maxi[20][10];
int n,r;// n=no of processes r=no of resources
int checkp(int p){
	for(int i=0;i<r;i++){
		if(need[p][i]>avail1[i])
			return 0;
	}
	return 1;
}

void safety(){
	int i,j;
	int f[10]={0};
	vector<int> v;
	while(1){
			int flag=0;
		for(i=0;i<n;i++){
			if(f[i]==0 && checkp(i))
			{
				flag=1;	
				v.push_back(i);
				break;
			} 
		}
		if(flag==1){
			for(int k=0;k<r;k++){
					avail1[k]+=allo[i][k];
				}
			f[i]=1;
			}
		else	
			break;
	}
	if(v.size()==n){
		vector<int>::iterator it;
		cout<<"Safe Sequence:";
		for(it=v.begin();it!=v.end();it++)
			cout<<*it<<" ";
		cout<<"\n";
	}
	else
		cout<<"Deadlock\n";

		return;
}
int main(){
	int i,j,a1,a2,a3;
	int ch,dp=1,f;
	int req[10];
	
			
		cin>>n>>r;
		for(i=0;i<n;i++)
			for(j=0;j<r;j++)
			scanf("%d",&allo[i][j]); //allocation matrix

		for(i=0;i<n;i++)
			for(j=0;j<r;j++)
			cin>>maxi[i][j];		// maximum matrix

		for(j=0;j<r;j++){
		scanf("%d",&avail[j]);
		avail1[j]=avail[j];
		}

		//Calculating need	
	for(i=0;i<n;i++){
		for(j=0;j<r;j++){
			need[i][j]=maxi[i][j]-allo[i][j];
						}
					}
	
					
				safety();

		scanf("%d",&i);
		 f=1;

		 for(j=0;j<r;j++){   	//copying the original available matrix
			avail1[j]=avail[j];
		}
		cout<<"\n";

		for(int k=0;k<r;k++)
			cin>>req[k];

		
		for(int k=0;k<r;k++){
			if(req[k]>avail1[k] || req[i]>need[i][k]){
				cout<<"Request can't be granted\n";
				f=0;
				break;
			}
			avail1[k]-=req[k];
			need[i][k]-=req[k];
			allo[i][k]+=req[k];
		}
		cout<<"\n";

			

			if(f==1)
			safety();

	return 0;

}

