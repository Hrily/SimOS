#include<iostream>
using namespace std;
struct file
{
	string nm;
	int size;
	int a[10];
	int* ptr=NULL;
};
	int index=0;
	struct file list[100];
	int block[64];
	int i;



	void addfile(string name, int s);
	void deletefile(string s);
	int * checkfile(int s);
	int searchfile(string s);
	

	void addfile(string name, int s){
		int * arr=checkfile(s);
		if(!arr){
			cout<<"Not possible\n";
			return ;
		}
		list[index].nm=name;
		list[index].size=s;
		for(int l=0 ; l<s ; l++ ){
		list[index].a[l]=arr[l];
		}
		for(int i=0; i<s ; i++){
			block[list[index].a[i]]=1; 
		}
		index++;
	}
	void deletefile(string s){
		int f=searchfile(s);
		if(f==-1){
			cout<<"File not found\n";
		}
		else{
			for(int i=0; i<list[f].size; i++){
				block[list[f].a[i]]=0; 
				}
		list[f].size=-1;
		}
	}
	int * checkfile(int s){
		int cnt=0;
		int* n=new int[10];
		for(int i=10;i<64;i++){
			if(block[i]==0){
				n[cnt++]=i;
				if(cnt>10)
					break;
			}

			if(cnt==s)
				return n;
		}
				
 		n=NULL;
		return n;
	}
	int searchfile(string s){
		for(int i=0; i<index; i++)
		if(list[i].nm==s && list[i].size!=-1){
			return i;
		}
	return -1;	

	}
	void display(){
	
	for (int j=0;j<index;j++){
		if(list[j].size==-1)
			continue;
		else{
		cout<<list[j].nm<<" "<<list[j].size<<" ";
			for(int i=0;i<list[j].size;i++)
				cout<<list[j].a[i]<<" ";
		}
		cout<<"\n";
	}
}
	int main(){
		int i;
	
	for(i=0; i<10; i++){
		block[i]=-1;
		
	}
	int ch,size,f;
	string name;
		
	while(1){
		cin>>ch;// 1.add 2. delete 3. display
		switch(ch){
		case 1:
			//Enter file name and size
			cin>>name>>size;
			addfile(name,size);
			break;
		case 2:
			cin>>name;
			deletefile(name);
			break;
		case 3:
			display();


	}
}
}