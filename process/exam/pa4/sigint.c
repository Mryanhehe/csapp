#include "csapp.h"

void sigint_handle(int sig){
	printf("Caught SIGINT\n");
	return ;
}

int main(){
	if(signal(SIGINT,sigint_handle) == SIG_ERR){
		unix_error("signal error");
	}
	pause();
	return 0; 
}

