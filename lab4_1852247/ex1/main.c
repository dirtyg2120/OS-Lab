#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"

int main(int argc, char * argv[])
{
	int align;
	for (int align = 2; align < 5000; align *= 2){
		void *p = aligned_malloc(1024, align);
		
		printf("%p, ( %ld %% %d ) = %ld \n", p, (long int)p, align, (long int)p%align);

		aligned_free(p);
	}

	return 0;
}
