#include <stdio.h> //printf, scanf
#include <unistd.h> //execlp
#include <stdlib.h> //EXIT_*
#include <sys/wait.h> //wait()


#define CHSIZE 200
#define LS_PATH "/bin/ls"
#define PS_PATH "/bin/ps"
#define DATE_PATH "/bin/date"
#define WHO_PATH "/usr/bin/who"
#define TTY_PATH "/usr/bin/tty"

int loop(void);
void launch(int args);
int readLine();
//char[] concat(char dest[], char source[]);
