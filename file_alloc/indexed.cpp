//Ritwick and Abhilash
#include<iostream>
#include<algorithm>
using namespace std;
typedef struct rit{
 	int ind;
 	int val;
 }rit;
struct file
{
	string nm;
	int size;
	rit a[10];
	int* ptr=NULL;
};
	int index=0;
	struct file list[100];
	
	typedef struct memloc{
		int i;
		bool occ;
	}memloc;
	memloc block[64];
 
  
  void addfile(string name, int s);
	void deletefile(string s);
	rit *checkfile(int s);
	int searchfile(string s);
	

	void addfile(string name, int s){
		if(searchfile(name)==-1){
		
		rit * arr=checkfile(s);
		if(!arr){
			cout<<"Not possible\n";
			return ;
		}
		list[index].nm=name;
		list[index].size=s;
		for(int l=0 ; l<s ; l++ ){
		list[index].a[l].ind=arr[l].ind;
		list[index].a[l].val=arr[l].val;
		}
		for(int i=0; i<s ; i++){
			block[list[index].a[i].ind].occ=1; 
		}
		index++;
	}
	else printf("File name already taken\n");
}
	void deletefile(string s){
		int f=searchfile(s);
		if(f==-1){
			cout<<"File not found\n";
		}
		else{
			for(int i=0; i<list[f].size; i++){
				block[list[f].a[i].ind].occ=0; 
				}
		list[f].size=-1;
		
		}
	}
	rit * checkfile(int s){
		int cnt=0;
		rit *n=new rit[10];
		for(int i=10;i<64;i++){
			if(block[i].occ==0){
				n[cnt].ind=i;
				n[cnt++].val=block[i].i;
				if(cnt>10){
					break;
				}
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
				cout<<list[j].a[i].val<<" ";
		}
		cout<<"\n";
	}
}
	int main(){
		int i;
	
	for(i=0; i<10; i++){
		block[i].i=-1;
		block[i].occ=1;
		
	}
	for(i=10; i<64; i++){
		block[i].i=i;
		block[i].occ=0;
	}
	random_shuffle(block+10,block + 64);
	
	int ch,size,f;
	string name;
		
	while(1){
		cin>>ch;// 1.add 2. delete 3. display 0.exit
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
			break;
		case 0: 
			exit(0);
			


	}
}
}
