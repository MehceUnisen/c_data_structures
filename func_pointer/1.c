#include <stdio.h>

void *helloFunc(){
	printf("Hello World");
	return NULL;
}

void funcIterator(void (*param_func)(), int iter){
	for(int i = 0; i < iter; i++){
		param_func();
	}
}

int main(){
	funcIterator(helloFunc, 31);	
	return 0;
}
