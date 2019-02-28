#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include <sys/stat.h>
//funcion que convierte a octal
int valor(char* a,char* b,char* c){
	int val;
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int x;

	for(int i = 0; i < 3; i++){
			if(i == 0)
				x = 2;
			if(i == 1)
				x = 1;
			if(i == 2)
				x = 0;
		if(a[i] == 'r' ||a[i] == 'w' || a[i] == 'x'){
			num1 += pow(2,x);
		}

		if(b[i] == 'r' ||b[i] == 'w' || b[i] == 'x'){
			num2 += pow(2,x);
		}

		if(c[i] == 'r' ||c[i] == 'w' || c[i] == 'x'){
			num3 += pow(2,x);
		}
	}

	val = num1*100 + num2*10 + num3;
	return val;
}


int main(){
	char path[] = "/home/diana/Documents/Codigos/SO/holis/";
	char archivo[10];
	char aux[100];
	char propietario[3];
	char grupo[3];
	char otros[3];

	printf("Nombre del archivo al que deseas hacer cambios \n");
	scanf("%s",archivo);

	strcpy(aux,path);
	//ponemos la cosa completa
	strcat(aux,archivo);
	//Opteniendo los valores para el propietario
	printf("Escribe los permisos que quieres para el propiertario\n");
	scanf("%s",propietario);

	//Opteniendo los valores para el grupo
	printf("Escribe los permisos que quieres para el grupo\n");
	scanf("%s",grupo);

	//Opteniendo los valores para el propietario
	printf("Escribe los permisos que quieres para los otros\n");
	scanf("%s",otros);

	int val= valor(propietario,grupo,otros);
	printf("el valor deseado es :%d \n", val);

	puts(aux);

	if (chmod (aux,val) < 0)
    {
	    puts("Murio");
    }
    return(0);

}


