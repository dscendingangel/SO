#include<stdio.h>
#include<unistd.h>
#include<pthread.h>


void hilo2(int n){
	pthread_t id_hilo;
	int x = 5;
	for(int i = 0; i < n; i++){
		pthread_create(&id_hilo,NULL,hilos,(void*)x);
		pthread_join(id_hilo,NULL);
	}
}

void* hilos(void* arg){
	int n = (int)arg;
	printf("En el  hilo: %d \n",pthread_self());
	hilo2(n);
	pthread_exit(NULL);
}

int main(void){
	//int id_proc;
	//id_proc = fork();
	pthread_t id_hilo;
	int n =  10;
	for(int i = 0; i < 15; i++){
		printf("numero del for : %d \n",i);
		pthread_create(&id_hilo,NULL,hilos,(void*)n);
		pthread_join(id_hilo,NULL);
	}
}


	
	
