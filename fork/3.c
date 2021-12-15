#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void createChildProcess(int forkNum);

int main(){
	createChildProcess(2);
	printf("Hello World\n");
	return 0;
}

void createChildProcess(int forkNum){
	for(int i = 0; i < forkNum; i++){
		fork();
	}
}

