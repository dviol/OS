/* Dennis Violante, Gr 5, 31.03.16
 * Grundlegende Systemcalls, im fokus hier: "fork()"
 * Der Code gibt seine PID aus, sowie "glob" und "var" 
 * */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int glob = 0;
char buf[] = "a write to stdout\n";
int main(void){
int var;	// Standartwert = 0
pid_t pid; // Standartwert = 0
var = 0;p

	if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1){ //Gibt einmalig buf[] in die Konsole aus
		perror("write error");
	}

printf("before fork\n");

	if ( (pid = fork()) < 0){ //Forked das Programm, falls der Wert < 0 wird ein Error ausgegeben. pid wird der Wert von fork() zugewiesen.
		perror("fork error");}
	else if (pid == 0) { //Wir befinden uns im Kindprozess, was durch die pid = 0 angezeigt wird
		printf("Ich bin child!pid=%d Parentid=%d\n",getpid(),getppid());
		glob++;
		var++; //glob und var werden um 1 inkrementiert
	}
	else{ //Wir befinden uns im Kindprozess, was durch die pid = 0 angezeigt wird
		printf("Ich bin parent!pid=%d Parentid=%d\n",getpid(),getppid());
		}
	sleep(4);


printf("pid = %d,patentid =%d, glob =%d, var = %d IsChild=%d\n", getpid(),getppid(), glob, var,pid==0);
/*
 * Die Reihenfolge variiert aufgrund des Scheduling zur Laufzeit variieren.
 * */

exit(0);
}
/*
Wenn es direkt in der Konsole ausgeführt wird, wird zunächst das Parent ausgeführt, geforked
jedoch führt das Child zuerst das Printf aus und die glob und var Variable erhöht, später das
Parent.
Wenn es in eine Textfile gepiped wird, wird wie erwartet zunächst das Parentprogramm und
dann das Childprogramm ausgeführt und geschrieben.

 * */
