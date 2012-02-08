#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
	int tmp;
	int a;
	int i;

	if (argc != 2)
		return 1;

	a = atoi(argv[1]);

	for (i = 0; i < 5; a>>=1, i++)
		printf("%d", a & 1);

	printf("\n");
	return 0;

}
