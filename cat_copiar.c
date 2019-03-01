#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
extern int errno;

int main(){
	
	char path[] = "/home/mapache/codigos/SO/";
	char buffer[100];  // a tratar
	char aux[100];
	char destino[100];
	char archivo[20];
	int op,file,num;

	while(1){
	printf("\nQue desea hacer? \n 1.Ver archivo \n 2.Copiar archivos \n 3. Salir \n ");
	scanf("%d",&op);

	switch(op){
		case 1: 
			{
			strcpy(aux,path);	
			strcat(aux,"holis");
			printf("Ingresa el nombre del archivo \n");
			scanf("%s",archivo);
			strcat(aux,"/");
			strcat(aux,archivo);
			//abrimos el archivo
			file = open(aux,O_RDONLY); 
			if (file < 0 ){
				printf("Error al abrir archivo \n");
			}
			read(file,buffer,100); //leemos el acrhivo
			close(file);
			puts(buffer); // lo imprimimos
			break;
			}
		case 2:
			{
			printf("¿Cuantos archivos quieres copiar?  \n");
			scanf("%d",&num);

			for(int i = 0; i<num ; i++){
				//limpaimos el destino para que no se concatene por siempre
				strcpy(destino,path);
				strcat(destino,"vais");
				strcat(destino,"/");
				// hacemos todo el path de origen
				strcpy(aux,path);	
				strcat(aux,"holis");
				strcat(aux,"/");
				printf("Introduce el nombre del archivo");
				scanf("%s",archivo);
				strcat(aux,archivo);

				strcat(destino,archivo);

				//abrimos el archivo a copiar
				file = open(aux,O_RDONLY); 
					if (file < 0 ){
						printf("Error al abrir archivo \n");
					}
				//leemos lo que vamos a copiar
				read(file,buffer,100);
				close(file);
				puts("Voy a crear el archivo nuevo");

        			file = open(destino, O_CREAT | O_WRONLY, 0644);
				if(file < 0 ){
					printf("Error al abrir el  archivo");
				}
				write(file,buffer,strlen(buffer));
				close(file);
			}
			break;
			}
		case 3:
			exit(0);
	}
}
}
