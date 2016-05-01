/* Dennis Violante
 * Gruppe 5
 * 26.04.16
 * A Simple shell which asks in the Shell for an integer which represent following commands:
 * exit(),who,date,ps,ls
 * No more commands are supported and will result in the termination of the program. No non Number shall
 * be entered.
 * */

#include "aufg04.h"

int main(int argc, char *argv[]){
	
	//Starting Loop
	loop();	
	
	//Will never be Executed
	return EXIT_SUCCESS;
	
}
	
int loop(){
	
	int arg = -1;
	printf("0 für exit\n1 für who\n2 für date\n3 für ps\n4 für ls\n=============================\n");
	
	//Infinite Promptloop, only terminates by invalid given number, or 0
	while(1){
		
		//Print Prompt
		printf("> ");
		
		//Call of the function readLine, which returns a int selector
		arg = readLine();
		
		//Launching the selected program
		launch(arg);
		
		//Resetting arg
		arg = -1;
	}
	
	//Should never be reached
	return 1;
		
}

//Reads an Integer from stdin, then returns it
int readLine(){

	int arg = -1;
	scanf("%i",&arg);
	return arg;
	
}

void launch(int arg){
	//If arg equals 0, we want to terminate the program
	if(arg == 0){
		printf("Auf Wiedersehen\nMade by Dennis Violante\n");
		exit(0);
	}
	//Wrong input, terminating
	else if(arg > 4 || arg < 1){
		printf("Ungültige eingabe, Terminiere\nMady by Dennis Violante\n");
		exit(1);
	}
	
	pid_t pid;
	pid = fork();

	//Here will the code execute
	if (pid == 0) {
		
		printf("Hallo, ich bin child und heiße %d\n",getpid());
		
		switch(arg) {
			case 1  :
				execlp(WHO_PATH,"who",NULL);
				break;
			case 2 :
				execlp(TTY_PATH,"tty",NULL);
				break;
			case 3 :
				execlp(PS_PATH,"ps",NULL);
				break;
			case 4  :
				execlp(LS_PATH,"ls",NULL);
				break;
			}
		//Should never be reached. Invalid input is catched before	
		exit(EXIT_FAILURE);
	} else if (pid < 0) {
		perror("Error Forking");
	} else {
		//Were in the Parent Process, wait for child
		wait(NULL);
	}
}



/* Old code which was my original solution, but due to the internship day on the 27.04.16 replaced by a less complicated variant
 * fully functional, only the header files must be reincluded and prototypes must be adjusted

int loop(){
  char *arg;
  int status;

  do {
    printf("> ");
    arg = readLine();
    status = launch(arg);
    free(arg);
  } while (status);	

return 1;	
}

char* readLine(){

char* line = NULL;

size_t buff = 0;
getline(&line,&buff,stdin);

return line;
	
}


int launch(char* arg){
	static int * glob_var;
  pid_t pid;
    glob_var = mmap(NULL,sizeof(*glob_var),PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS, -1, 0);

    *glob_var = 1;
 
  pid = fork();
  if (pid == 0) {

	
	if(strncmp(arg,"who",strlen("who")) == 0){
			printf("I'm in who!\n");
			execlp(WHO_PATH,"who",NULL);
	}else if(strncmp(arg,"date",strlen("date")) == 0){
					execlp(WHO_PATH,"who",NULL);

	}else if(strncmp(arg,"tty",strlen("tty")) == 0){
					execlp(TTY_PATH,"tty",NULL);

	}else if(strncmp(arg,"ps",strlen("ps")) == 0){
					execlp(PS_PATH,"ps",NULL);

		
	}else if(strncmp(arg,"ls",strlen("ls")) == 0){
					execlp(LS_PATH,"ls",NULL);

	}else if(strncmp(arg,"exit",strlen("exit")) == 0){
		*glob_var=0;
		
	}else{
		printf("Unnknown command, terminating.\n");
		*glob_var=0;
	}


    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    perror("Error Forking");
  } else {
      wait(NULL);
  }
  

  return *glob_var;
		
	
}*/
