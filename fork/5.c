#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void createFork(int forkNum){
	int x = 0;
	for(int i = 0; i < forkNum; i++){
		if(fork() == 0){
			printf("Hello From Child -> %d\n", ++x);
		}
		else{
			printf("Hello from parent -> %d\n", ++x);
		}
	}	
}

int main(){
	createFork(3);	
	return 0;
}
