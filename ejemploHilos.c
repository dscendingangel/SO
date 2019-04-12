#include<stdio.h>
#include<pthread.h>

void* hilo(void* arg){
	printf("Hola mundo desde un hilo de UNIX \n");
	return NULL;
}

int main(void){
	pthread_t id_hilo;
	pthread_create(&id_hilo,NULL,(void*)hilo,NULL);
	pthread_join(id_hilo,NULL);
	return 0;
}

