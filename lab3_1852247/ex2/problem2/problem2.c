#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	printf("%d\n", getpid()); 
    pid_t B, C, D, E, F, G, I;
    B = fork();
    if(B == 0) {
    	E = fork();
    	if(E == 0) {
    		I = fork();
    		sleep(2);
    	}
    	else {
    		F = fork();
    		sleep(2);
    	}
    }
    else {
    	C = fork();
	    if(C == 0){
	    	G = fork();
	    	if(G > 0) 
	    		sleep(2);
	    }
	    else {
	    	D = fork();
	    	sleep(3);
	    }
    }

    return 0;
}
