#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
extern int errno;

int main(){
	
	//char path[] = "/home/mapache/codigos/SO/";
	char path[] = "/home/diana/Documents/Codigos/SO/";
	char aux[100];
	char destino[100];
	char archivo[20];
	char* buffer;
	size_t n = 16;

	int op,file;

	printf("Que desea hacer? \n 1.Ver archivo \n 2.Mover archivos ");
	scanf("%d",&op);

	strcpy(aux,path);	
	strcat(aux,"holis");
	printf("Ingresa el nombre del archivo \n");
	scanf("%s",archivo);
	strcat(aux,"/");
	strcat(aux,archivo);

	puts(buffer);

	switch(op){
		case 1: 
			{
			//abrimos el archivo
			file = open(aux,O_RDONLY); 
			if(file == -1){
				printf("Error file : %d \n",errno);
				perror("Programa");
			}
			if(read(file,buffer,n) <= 0){
				printf("Error al leer :%d\n",errno);
				if(read(file,buffer,n) == -1){
					puts("Fue igual a -1");
				}
			}

			puts(buffer);
			break;
			}
		case 2:
			{
			strcpy(destino,path);
			strcat(destino,"vais");
			break;
			}
	}
}
