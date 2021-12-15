#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *myThreadFun(void *vargp){
	sleep(1);
	printf("Printing From Thread Process\n");
	return NULL;
}

int main(){
	pthread_t thread_id;
	printf("Before thread");
	
	pthread_create(&thread_id, NULL, myThreadFun, NULL);
	pthread_join(thread_id, NULL);
	
	printf("After thread");
	

	return 0;
}
