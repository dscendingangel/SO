#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void hijosLinea (int n){
	if(n != 0){
		int pid;
		pid = fork();
		if(pid == 0){
			printf("Mi pid es %d, y mi padre es ; %d \n",getpid(),getppid());
			hijosLinea(n-1);
		}
		else{
			wait(0);
		}
	}
	else{
		return;
	}
}

int main(void)
{
	int id;
	if( id != 0){
		printf("Soy el proceso padre padre mi pid es %d \n",getpid());
	}
		wait(0);
	for(int i=0; i<10; i++){
		id = fork();
		if(id == 0){
			printf("%dMi pid es %d, y mi padre es : %d \n",i+1,getpid(),getppid());
			hijosLinea(10-i);
			exit(0);
		}
		else{
			wait(0);
		}
	}
}


