//main
#include <stdio.h>
#include "readline.h"
#include "findsubstr.h"

int main(int argc, char * argv[]) {
	// Implement mygrep

	char str[1000];
	FILE *fp = fopen(argv[1], "r");

	char *new = argv[2];
	int size = 0;
	while(new[++size] != '\0');
	if(argc > 3) {
		for(int i = 3; i < argc; i++) {
			//
			//
			int sub_size = 0;
			while(argv[i][++sub_size] != '\0');
			//
			//
			new[size] = ' ';
			for (int j = 0; j < sub_size; j++)
			{
				new[++size] = argv[i][j];
			}
			size++;
		}
	}

	int i = 1;
	int flag = 0;
	while(fgets(str, 1000, fp) != NULL) {
		if(find_sub_string(str, new) != -1) {
			printf("Line %d: %s", i, str);
			flag = 1;
		} else {
			i++;
			continue;
		}
		i++;	
	}
	if (flag == 0)
	{
		printf("%d\n", -1);
	}

	fclose(fp);
}
