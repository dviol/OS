#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>

/*
 * Dennis Violante
 * Gruppe 5
 * 09.04.16
 * chroot(char* path)
 * "chroot runs a command with a specified root directory (path parameter). On many systems (like mine), only the super-user can do this"
 * 
 * void* dlopen(char* path,int size)
 * Returns a handle to the in paht specified Dynamic Linked Library
 * 
 * void* dlsym(void* handle,char* func)
 * 
 * Returns a function pointer to the in func specified function, from the handle
 * 
 * int dlclose(void* handle)
 * 
 * Closes the handle
 * 
http://linux.die.net/man/2/chroot
 * */




int main(void){
	
	//The absolut path to the jail
	char* path = "/home/v1ol/Documents/ftp/uniSem4/OS/Solutions/Aufg02/jail";
	
	//The path to the needed .so file (Dynamically linked Library)
	char* pathm = "/lib/x86_64-linux-gnu/libm.so.6";
	
	//The handle to use, for errorchecking and later to init the function
	void *handle;
	
	//The function pointer as placeholder for the Sinus function
	double (*sin) (double);
	

	//Returns the handlepointer (before chroot)
	handle = dlopen(pathm,RTLD_NOW);
	
	//If handle is null, something went wrong
	if(!handle){
			dlerror();
			printf("Dlopen failed!\n");
			exit(1);
		}
	
	//The sin pointe gets the function out of dlsym	
	sin = (double (*) (double)) dlsym(handle,"sin");

	//For debugging
	printf("Before chroot\n--------\n\n");
	
	//Prints out the value of sin(2.0)
	printf("Sinus of 2 is: %lf\n\n",(*sin)(2.0));
	
	//Handle gets closed
	dlclose(handle);

//Chroots into the in the path defined directory and makes it for the program the new root dir
	if(chroot(path) != 0){
		perror("ChrootError");
		exit(1);
	}else{ //Chroot worked, new root directory made
	
	//Same as before but chrooted	
	handle = dlopen(pathm,RTLD_NOW);
	
	if(!handle){
		perror(dlerror());
		exit(1);
		}
	sin = (double (*) (double)) dlsym(handle,"sin");
		
  
	printf("Sinus of 0 is: %lf\n\n",(*sin)(0.0));	

	
}

exit(0);
}
