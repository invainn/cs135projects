#include <stdio.h>
#include <ctime>
#include <stdlib.h>

int main(int argc, char* argv[]) {

	int x = atoi(argv[1]);
	int y = 0;
	int random = 0;
	srand(time(NULL));

	for(int c = 0; c < x; c++) {
		random = rand()%200001 - 100000;
		printf("%d\n", random);
	}
	
	return 0;
}
