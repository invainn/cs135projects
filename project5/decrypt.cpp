#include <iostream>
#include <cstring>
#include <cstdio>

#include "rotUtils.h"

using namespace std;

void read(char** a, FILE* b, int &x);
void rotateArray(char** a, char** b, int x1, int x2);

int main(int argc, char* argv[]) {

	int countx = 0;
	int countdx = 0;

	char** x = new char*[100000];
	char** dictx = new char*[100000];

	for(int i = 0; i < 100000; i++) {
		x[i] = new char[60];
		dictx[i] = new char[60];
	}


	bool xswitch = false;

	FILE* file = fopen(argv[1], "r");
	FILE* dict = fopen(argv[2], "r");

	if(file == NULL || dict == NULL) {
		printf("File does not exist\n");
		return 0;
	}	

	read(x, file, countx);
	read(dictx, dict, countdx);

	rotateArray(x, dictx, countx, countdx); 

	return 0;
}

void read(char** a, FILE* b, int &x) {

	int i = 0;

	while(i != EOF){ 
		i = fscanf(b, "%s", a[x]);
		x++;
	}

	rewind(b);		
}

void rotateArray(char** a, char** b, int x1, int x2) {

	int k = 1;
	char* ptemp = NULL;

	for(int i = 0; i < x1; i++) {

		if(k >= 200) {
			printf("Could not find encryption key\n");
			break;
		}
		for(int n = 0; n < strlen(a[i])-1; n++) {
			a[i][n] = rotate(a[i][n], k);	
		}
		for(int m = 0; m < x2; m++) {
			ptemp = strstr(a[i], b[m]);	
		}
		
		if(ptemp != NULL) {
			printf("The key is %d\n", k);
			printf("The decrypted text is,\n");
			for(int i = 0; i < x1; i++) {
				printf("%s ", a[i]);
			}
			break;
		}
	}
}
