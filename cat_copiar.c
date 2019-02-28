#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
extern int errno;

int main(){
	
	char path[] = "/home/mapache/codigos/SO/";
//	char buffer[];  // a tratar
	char aux[100];
	char destino[100];
	char archivo[20];

	int op,file;

	printf("Que desea hacer? \n 1.Ver archivo \n 2.Mover archivos ");
	scanf("%d",&op);

	strcpy(aux,path);	
	strcat(aux,"holis");
	printf("Ingresa el nombre del archivo \n");
	scanf("%s",archivo);
	strcat(aux,"/");
	strcat(aux,archivo);

	switch(op){
		case 1: 
			{
			//abrimos el archivo
			file = open(aux, 
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
