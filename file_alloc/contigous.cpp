// Abhilash and Ritwick
#include<iostream>
#include<cstdio>
using namespace std;

struct file
{
	string nm;
	int i;
	int size;
};
	int index=0;
	struct file list[20];
	bool block[64]={0};
int searchfile( string s);
int checkfile(int size);
int addfile(string s,int k){
	
	 int f=checkfile(k);	

	if(f==-1){
		cout<<"ERROR\n";
		fflush(stdout);
		return 0;
	}else{
		list[index].nm=s;
		list[index].size=k;	
		list[index++].i=f;
		for(int j=f;j<f+k;j++)
				block[j]=1;
		return 1;
	}
	return 0;
}

int deletefile(string s){
	int f=searchfile(s);	
	if(f==-1){
		cout<<"ERROR\n";
		fflush(stdout);
		return 0;
	}
	int in=list[f].i;
	int si=list[f].size;
	for(int j=in;j<in+si;j++)
		block[j]=0;
	list[f].i=-1;
	return 1;
}
int checkfile(int size){
	int j=0,k;
	while(j<64-size){
		if(block[j]==0){
				for(k=0;block[j+k]==0 && k<size; k++);
					if(k==size)
						return j;
					else
						j+=k;
		}
		else
			j++;
	}

	return -1;
}

int searchfile( string s){
	for(int i=0 ; i<20; i++)
		if(list[i].nm==s){
			return i;
		}
	return -1;	
}
void display(){
	for (int j=0;j<index;j++){
		if(list[j].i==-1)
			continue;
		else
		cout<<list[j].size<<" "<<list[j].i<<" ";
	}
	cout<<endl;
	fflush(stdout);
}
int main(){
	int ch,size,f;
	string name;
		
	while(1){
		cin>>ch;// 1.add 2. delete 3. display
		switch(ch){
		case 1:
			//Enter file name and size
			cin>>name>>size;
			fflush(stdin);
			if(addfile(name,size))
				display();
			break;
		case 2:
			cin>>name;
			fflush(stdin);
			if(deletefile(name))
				display();
			break;
		case 3:
			display();
			break;
		case 0:
			return 0;
	}
}
}
