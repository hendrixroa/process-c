#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char *argv[]){
	
pid_t process;

int file;
int n,val;

		mkfifo("pipe",0666);
		process=fork();
			if(process==0){
			printf("soy hijo %d\n",getpid());
			file=open("pipe",O_WRONLY);
			char *buffer;
			buffer=(char *) calloc(100, sizeof(char));
			val=getpid();
			sprintf(buffer,"%d",val);
			n=strlen(buffer);
			printf("Y Escribi :%s\n",buffer);
			printf(" Escribe en %d\n",write(file,buffer,n));
			sleep(1);
			close(file);
			exit(1);
			}
	else{
	int fil=open("pipe",O_RDONLY);
	char * buf = (char *) calloc(100, sizeof(char));
	read(fil,buf,9000);
	printf("Soy Papa y lei :%s\n",buf);
	close(fil);
	system("rm pipe");
	exit(1);
}
return 0;
}
