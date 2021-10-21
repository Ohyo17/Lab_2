#include <stdlib.h> /* needed to define exit() */
#include <unistd.h> /* needed for fork() and getpid() */
#include <stdio.h> /* needed for print */
#include <sys/wait.h> /* waitpid file */
int main(int argc, char **argv){

int pid; /*processID*/


switch (pid = fork()){

case 0: printf("I am the child process : pid = %d \n " , getpid());
	break ; /* a fork returns 0 to the child */

default:wait(NULL);
	printf(" I am the parent process : pid = %d,child pid=%d \n ",getpid(),pid);
	break; /* a fork returns a pid to the parent */

case -1:perror ("fork");
	exit(1); /* Something went wrong */
}

exit(0);

}

