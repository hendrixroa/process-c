#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){

pid_t PID1,PID2;
  char *c1,*c2,*res;
  int finalizado1=0,finalizado2=0,auxhijo,estado;
  
  c1 = (char *) calloc(100, sizeof(char));
  c2 = (char *) calloc(100, sizeof(char)); 
  res = (char *) calloc(200, sizeof(char));
  
  PID1 = vfork();
  
  if(PID1 == 0){//SOY HIJO
	  printf("Soy hijo 1 :\n");
	  read(0,c1,99);//leo por pantalla la cadena 
	  exit(0); //finalizo exitosamente
  }
  
  PID2 = vfork();
  
  if(PID2 == 0 ){ //soy hijo2
	  	  printf("Soy hijo 2 :\n"); 
	  read(0,c2,99);//leo por pantalla la cadena
	 exit(0); //finalizo
  }
  
  if(PID1 < 0 || PID2 < 0){ //veo si hay error con los hijos
	  printf("Error con alguno de los dos hijos \n");
	  exit(1);//finalizo con error
  }
  
  if((PID1 > 0) && (PID2 > 0)){ //si soy el padre de los 2  
	  	  printf("Soy Papa :\n");
	  while((!finalizado1) || (!finalizado2)){
	  auxhijo = wait(&estado);  //obtengo el estado de los hijos
			if(auxhijo == PID1){ //si hijo1 finalizo
		    finalizado1 = 1;
			}	  
			if(auxhijo == PID2){ //si hijo2 finalizo
		    finalizado2 = 1;
			}
	  }
	  strcpy(res,c1);//copio cadena en res
	  strcat(res,c2);//le añado la otra cadena a res
	  printf("Cadena Resultante :%s\n",res);  //imprimo
  }
return 0;
}
