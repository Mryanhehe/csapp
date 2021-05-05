#include "csapp.h"
#define N 2

int main(){
	int status;
	pid_t pid;
	for(int i = 0 ; i < N ;i++){
		if((pid = Fork()) == 0){
			exit(100+i);
		}
	}
	while ((pid = waitpid(-1,&status,0))>0 ){
		if(WIFEXITED(status)){
			printf("children %d terminated %d\n",pid ,WEXITSTATUS(status));
		}
		else
			printf("children %d terminated \n",pid);
	}
	if(errno != ECHILD)
		unix_error("waitpid error");
	return 0;
}
