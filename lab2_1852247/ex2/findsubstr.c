#include "findsubstr.h"

int find_sub_string(const char *str, const char *sub) {
	int i = 0, j = 0;
	int firstOccur = 0;

	while(j == 0) {
		while(str[i] != sub[0] && str[i] != '\0') {
			i++;
		}

		firstOccur = i;

		while(str[i] == sub[j]) {
			i++;
			j++;
		}
		if(sub[j] != '\0' && str[i] != '\0') {
			j = 0;
		} else break;
	}

	if(sub[j] == '\0')
		return firstOccur;
	else return -1;
}
