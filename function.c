#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void childTask(){
printf("Salam, saya anak tau \n ");
}

void parentTask(){
printf("dan saya adalah bapaknya \n ");
}

int main(void){

pid_t pid = fork ();

if (pid == 0){
childTask();
printf("Child process: PPID=%d , PID=%d \n " , getppid(),getpid());
exit(EXIT_SUCCESS);
}
else if (pid > 0){
wait(NULL);
parentTask();
printf("Parent Process : PID=%d \n", getpid());
}
else {
printf("Unable to create child process\n");
}

return EXIT_SUCCESS;

}
