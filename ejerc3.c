#include <stdio.h>
#include <unistd.h>  
#include <signal.h>
#include <stdlib.h>

pid_t process;

void manejadorDeSenales(pid_t process);
int main(){
char opcion;
(void) signal(SIGUSR1,manejadorDeSenales); 

		while(1==1){
			if((int)signal(SIGUSR1,manejadorDeSenales)==SIGINT){
				perror("se mata al hijo");
			}
			
		read(0,&opcion,1);	
		
		if(opcion =='S'){
			printf("detiendo al hijo\n");
			kill(process,SIGSTOP);
		}	
		
		if(opcion =='G'){//AL HIJO
			printf("reanudando al hijo\n");
			kill(process,SIGCONT);	
		}	
		
		if(opcion =='F'){//AL PADRE
			printf("matando al padre\n");
			kill(process,SIGSTOP);
			exit(1);
		}	
		
		if(opcion =='C'){
		process=fork();
		if(process == 0){
			printf("hola soy hijo\n");
        execlp("./interface","interface",NULL);
		}
		}			
		}
	}
		
void manejadorDeSenales(pid_t process){
	kill(process,SIGTERM);
}
	

