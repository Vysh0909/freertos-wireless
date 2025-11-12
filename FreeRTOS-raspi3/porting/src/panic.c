#include <stdio.h>

void panic(void)
{
	printf("An error occured! Aborting...\n");
	abort();
}
