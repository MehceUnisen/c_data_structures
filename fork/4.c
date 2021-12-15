#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void createFork(int forkNum){
	for(int i = 0; i < forkNum; i++){
		if(fork() == 0){
			printf("Hello From Child\n");
		}
		else{
			printf("Hello from parent\n");
		}
	}	
}

int main(){
	createFork(3);	
	return 0;
}
