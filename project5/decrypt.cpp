#include <iostream>
#include <string.h>
#include <cstdio>

#include "rotUtils.h"

using namespace std;

void read(char** a, FILE* b, int &x);
void rotateArray(char* a, char** b, int x1, int x2);

int main(int argc, char* argv[]) {

	int test = 0;
	int ac = 0;

	int countx = 0;
	int countdx = 0;

	// change to 1d array?
	char* x = new char[100000];
	char** dictx = new char*[100000];

	for(int i = 0; i < 100000; i++) {
		dictx[i] = new char[60];
	}


	bool xswitch = false;

	FILE* file = fopen(argv[1], "r");
	FILE* dict = fopen(argv[2], "r");

	if(file == NULL || dict == NULL) {
		printf("File does not exist\n");
		return 0;
	}	

	while((test = getc(file)) != EOF) {
		x[countx] = test;
		countx++;
	}
	x[countx] = '\0';

	rewind(file);
	
	cout << x << endl;

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
	a[x]='\0';
	rewind(b);		
}

void rotateArray(char* a, char** b, int x1, int x2) {
	int kSolution = 0;

	char* ptemp = NULL;
	
	char* temp = new char[20000];
		
	strcpy(temp, a);

	for(int k = -50; k < 50; k++) {
		for(int n = 0; n < strlen(a); n++) {
			if(a[n] != '\n' && a[n] != ' ' && a[n] != '\t') {
				temp[n] = rotate(a[n], k);
			}
		}
		cout << temp << endl;
		for(int m = 0; m < x2; m++) {
			ptemp = strstr(a, b[m]);
			if(ptemp != 0) {
				cout << "Key is " << k << endl;
				cout << temp << endl;
				return;
			} else {
				delete(temp);
				temp = new char[20000];
				strcpy(temp, a);
			}
		}
	}

}
