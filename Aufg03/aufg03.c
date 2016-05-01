/* Dennis Violante
 * Gruppe 5
 * 09.04.16*/

#include <stdio.h>
#include <dlfcn.h>

int (*addTwo) (int);
int (*addTwo_other) (int);
void *handler;
char pathlib[] = "./mylib.so";


int main(){
	
	handler = dlopen(pathlib,RTLD_NOW);
	
	if(!handler){
		
		perror("Dlopen not functional");
		return 1;
	}
	//assigning the functionpointer to addTwo and -_other
	addTwo = (int (*) (int)) dlsym(handler,"addTwo");
	addTwo_other = (int (*) (int)) dlsym(handler,"addTwoLoc");
	
	/*Just as in Aufgabe 02, a normal function call from a .so file.*/
	
	printf("Add two to 1 yields %i\n",(*addTwo)(1));
	
	/*Memory access error, because it is a static function (method is only visible in the file itself, because of the
	static tag)*/
	printf("Add two to 1 yields %i\n",(*addTwo_other)(1));
	
	
	return 0;
}
