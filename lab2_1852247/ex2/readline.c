#include "readline.h"

int read_line(char *str) {
	if(str[0] == '\0')
		return -1;
	else {
		int size = 0;
		for(size; str[size] != '\0'; size++);
		return size;
	}
}

