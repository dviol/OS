#include <sys/types.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>

 /* Read characters from the pipe and echo them to stdout. */

 void
 read_from_pipe (int file)
 {
   FILE *stream;
   int c;
   stream = fdopen (file, "r");
   while ((c = fgetc (stream)) != EOF)
     putchar (c);
   printf("\n"),
   fclose (stream);
 }

 /* Write some random text to the pipe. */

 void
 write_to_pipe (int file,char in[])
 {
   FILE *stream;
   stream = fdopen (file, "w");
   fprintf (stream, in);
   fclose (stream);
 }

 int
 main (void)
 {
	
	pid_t pid;
	int mypipe[2];

   /* Create the pipe. */
   if (pipe (mypipe))
     {
       fprintf (stderr, "Pipe failed.\n");
       return EXIT_FAILURE;
     }

   /* Create the child process. */
   pid = fork ();
   if (pid == (pid_t) 0)
     {
       /* This is the child process.
          Close other end first. */
       close (mypipe[1]);
      // printf("Hallo ich bin Kind\n");
       read_from_pipe (mypipe[0]);
       return EXIT_SUCCESS;
     }
   else if (pid < (pid_t) 0)
     {
       /* The fork failed. */
       fprintf (stderr, "Fork failed.\n");
       return EXIT_FAILURE;
     }
   else
     {
		int s1,s2;
		if(scanf("%d,%d",&s1,&s2) != 2){
			fprintf(stderr, "geben Sie zwei Intergerzahlen ein\n");
			return 1;
			}
       /* This is the parent process.
          Close other end first. */
       //printf("Hallo ich bin Vater\n");
       close (mypipe[0]);
       char in[] = {(char) (s1+s2+'0'),0};
       write_to_pipe (mypipe[1],in);
       return EXIT_SUCCESS;
     }
 }
