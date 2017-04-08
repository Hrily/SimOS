//Ritwick and Abhilash
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct file
{
	string nm;
	int size;
	
	struct memloc* ptr=NULL;
};
struct memloc{
	int i;
	int fileid;
	struct memloc* next;
	bool occ;
};
	int index=0;
	struct file list[100];
	struct memloc *block=new struct memloc[64];
	
		
	int addfile(string name, int s);
	int deletefile(string s);
	struct memloc * checkfile(int s);
	int searchfile(string s);
	
struct memloc * checkfile(int s){
		int cnt=0;
		struct memloc *a=NULL;
		struct memloc *temp=NULL;
		temp=a;
		for(int i=0; i<64; i++){
			if(block[i].occ==0){
				if(a==NULL){
					a=&block[i];
					temp=a;
				}
				else{
				temp->next=&block[i];
				temp=temp->next;
				}
				cnt++;
			}
			if(cnt==s){
				temp->next=NULL;
				return a;
			}
			
			
		}
		return NULL;
		
		
		
	}
	
	int addfile(string name, int s){
		if(searchfile(name)==-1){
		
		 struct memloc *arr =checkfile(s);
		 if(arr==NULL){
		 	cout<<"File can't be allocated\n";
			fflush(stdout);
		 	return 0;
		 }
		 list[index].nm=name;
		 list[index].size=s;
		 list[index].ptr=arr;
		 struct memloc *temp=arr;
		 for(int i=0; i<s; i++){
		 	if(temp!=NULL){
		 		temp->fileid=index;
		 		temp->occ=1;
		 		temp=temp->next;
		 		
			 }
		 }
		 index++;
		 return 1;
	}
	else{
		printf("File name already taken\n");
		fflush(stdout);
		return 0;
	}
	}
	int searchfile(string s){
		for(int i=0; i<index; i++)
		if(list[i].nm==s && list[i].size!=-1){
			return i;
		}
		
	return -1;	
}
	int deletefile(string s){
		int f=searchfile(s);
		if(f==-1){
			cout<<"File not found\n";
			fflush(stdout);
			return 0;
		}
		memloc * arr=list[f].ptr;
		while(arr!=NULL){
			arr->occ=0;
			arr=arr->next;
		}
		list[f].size=-1;
		
		return 1;
		
	}
	
void display(){
	for (int j=0;j<index;j++){
		if(list[j].size==-1)
			continue;
		else{
			struct memloc * temp=list[j].ptr;
		cout<<list[j].nm<<" "<<list[j].size<<" ";
		while(temp!=NULL){
			cout<<temp->i<<" ";
			temp=temp->next;
		}
		cout<<"<br>";
	}
}
	cout<<endl;
	fflush(stdout);
}
int main(){
		int j;
	for(j=0; j<64; j++){
		block[j].i=j;
		block[j].occ=0;
	}
	random_shuffle(block,block + 64);

	
	int ch,size,f;
	string name;
		
	while(1){
		cin>>ch;// 1.add 2. delete 3. display 0.exit
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
			exit(0);


	}
	}
	return 0;
}
