#include<stdio.h>
#include<pthread.h>

void* hilo(void* arg){
	char* men;
	int resultado_hilo = 0;
	men = (char*)arg; //cast del argumento enviado
	printf("%s\n",men);
	resultado_hilo = 100;
	pthread_exit((void*)resultado_hilo);//cosa a enviar, casteada
}

int main(void){
	pthread_t id_hilo;
	char* mensaje="Holis qu tranza";
	int devolucion_hilo;
	pthread_create(&id_hilo,NULL,hilo,(void*)mensaje); //(el hilo que creamos,tipo de hilo,nombre de la funcion,argumento a enviarSOLO UNO)
	pthread_join(id_hilo,(void*)&devolucion_hilo);// el hilo que creamos,dode vamos a guardar lo que nos devuelve
	printf("valor = %i\n",devolucion_hilo);
	return 0;
}


