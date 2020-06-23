#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char * argv[]) {
	

	pid_t pid = fork();

	if (pid == -1) {
		perror ("fork");
		exit (1);
	}
	else if(pid == 0) {
		int numbChild = 0;
		char str[1000];
		FILE *fp = fopen("numbers.txt", "r");
		while(fgets(str, 1000, fp) != NULL) {
			if(atoi(str) % 3 == 0 ) 
				numbChild++;
		}
		fclose(fp);
		printf("%d\n", numbChild);
		
	} else {
		int numbParent = 0;
		char str[1000];
		FILE *fp = fopen("numbers.txt", "r");
		while(fgets(str, 1000, fp) != NULL) {
			if(atoi(str) % 2 == 0)
				numbParent++;
		}
		fclose(fp);
		printf("%d\n", numbParent);
	}
	
	return 0;
}
