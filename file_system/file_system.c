#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int len(char n[]){
	int l=0;
	while(n[l]!='\0') l++;
	return l;
}

int eq(char n[], char m[]){
	int l = len(n);
	int k = len(m);
	if(l!=k) return 0;
	for(int i=0;i<l;i++)
		if(n[i]!=m[i])
			return 0;
	return 1;
}

struct file{
	char name[32];
	int isD, nChild;
	struct file *child[100];
	file(){
		nChild = 0;
	}
	file(char n[], int d){
		strcpy(name, n);
		isD = d;
		nChild = 0;
	}
	int hasChild(char n[]){
		for(int i=0;i<nChild;i++){
			if(eq(child[i]->name, n))
				return i;
		}
		return -1;
	}
	int addChild(struct file f){
		if(hasChild(f.name)>=0)
			return 0;
		child[nChild] = (struct file*) malloc(sizeof(struct file));
		strcpy(child[nChild]->name, f.name);
		child[nChild]->isD = f.isD;
		if(f.isD==1){
			child[nChild]->child[0] = this;
			child[nChild]->nChild++;
		}
		nChild++;
		return 1;
	}
	struct file* getChild(char n[]){
		int h = hasChild(n);
		if(h<0){
			printf("hrish: %s: No such file or directory\n");
			fflush(stdout);
			return NULL;
		}
		return child[h];
	}
	void ls(){
		for(int i=0;i<nChild;i++){
			if(child[i]->isD && i==0)
				printf("..\t\t");
			else
				printf("%s\t\t", child[i]->name);
			if(child[i]->isD)
				printf("DIR");
			printf("<br>");
		}
		printf("\n");
		fflush(stdout);
	}
};

int main(){
	// printf("Welcome to\n\n");
	// printf("  _                         _\n");
	// printf(" | |            [*]        | |     \n");
	// printf(" | |____   ___   _   ____  | |____ \n");
	// printf(" |  __  | |  _| | | |  __| |  __  |\n");
	// printf(" | |  | | | |   | |  \\ \\   | |  | |\n");
	// printf(" | |  | | | |   | |  _\\ \\  | |  | |\n");
	// printf(" |_|  |_| |_|   |_| |____| |_|  |_|\n\n");
	fflush(stdout);
	struct file *root, *wd;
	root = (struct file*) malloc(sizeof(struct file));
	strcpy(root->name, "/");
	root->nChild = 0;
	root->isD = 1;
	root->addChild(file("file1", 0));
	root->addChild(file("file2", 0));
	root->addChild(file("file3", 0));
	char command[100], name[100];
	command[0] = '\0';
	wd = root;
	while(!eq(command, "quit")){
		// printf("$ ");
		scanf("%s",command);
		if(eq(command, "ls")){
			fflush(stdin);
			wd->ls();
			fflush(stdout);
		}else if(eq(command, "search")){
			scanf("%s", name);
			fflush(stdin);
			if(wd->hasChild(name)<0)
				printf("hrish: %s does not exist\n", name);
			else
				printf("hrish: %s exists\n", name);
		}else if(eq(command, "touch")){
			scanf("%s", name);
			fflush(stdin);
			fflush(stdout);
			if(wd->addChild(file(name,0)))
				printf("\n");
			else
				printf("hrish: %s already exists\n", name);
		}else if(eq(command, "cd")){
			scanf("%s", name);
			fflush(stdin);
			if(eq(name, "..") && wd->child[0]->isD){
				wd = wd->child[0];
				printf("\n");
				fflush(stdout);
				continue;
			}
			if(wd->hasChild(name)<0){
				printf("hrish: %s: No such directory\n", name);
				fflush(stdout);
				continue;
			}
			struct file *f = wd->getChild(name);
			if(f->isD==0){
				printf("hrish: %s is not a directory\n", name);
				fflush(stdout);
				continue;
			}
			wd = f;
			printf("\n");
		}else if(eq(command, "mkdir")){
			scanf("%s", name);
			fflush(stdin);
			if(wd->hasChild(name)>=0){
				printf("hrish: %s already exists\n", name);
				fflush(stdout);
				continue;
			}else
				printf("\n");
			wd->addChild(file(name, 1));
		}
		else if(!eq(command, "quit")){
			fflush(stdin);
			printf("hrish: bad command\n");
		}
		char *b;
		size_t l = 80;
		getline(&b, &l, stdin);
		fflush(stdout);
	}
}
