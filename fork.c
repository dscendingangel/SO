#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(void)
{
	int id;
	if( id != 0){
		printf("Soy el proceso padre padre mi pid es %d \n",getpid());
	}
	for(int i=0; i<10; i++){
		id = fork();
		if(id == 0){
		printf("Mi pid es %d, y mi padre es ; %d \n",getpid(),getppid());
		}
		exit(0);
		int n = 10 - i;
		for(int j = 0; j < n ; j++){
			id = fork();
			if(id == 0){
			printf("Mi pid es %d, y mi padre es ; %d \n",getpid(),getppid());
			}
			exit(0);
			if ( j =
		}


	}
}


