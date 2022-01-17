#include <stdio.h>

void *helloFunc(){
	printf("Hello World");
	return NULL;
}

void func_iterator(void (*param_func)(), int iter){
	for(int i = 0; i < iter; i++){
		param_func();
	}
}

int main(){
    func_iterator(helloFunc, 31);	
	return 0;
}

