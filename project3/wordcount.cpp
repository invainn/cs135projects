#include <stdio.h>

int main(int argc, char* argv[]) {

	// boolean y is used as a switch to be false when a word is counted
	// and to be true when if it is not a word
	bool y = false;
	bool d = false;

	// int x is used to retrieve the next char from the file
	int x = 0;
	int chars = 0;
	int nonws = 0;
	int lines = 0;
	int wc = 0;
	int nonblank = 0;

	// object pointer file grabs the file name and reads it
	FILE* file = fopen(argv[1], "r");

	if(file == NULL){
		printf("Could not open file\n");
		return 0;
	}

	// loops until end-of-file	
	while((x = fgetc(file)) != EOF) {
		if(x != '\n' && x != ' ' && x != '\t') {
			nonws++;
			if(y == false) {
				y = true;
				wc++;	
			}
			if(d == false) {
				d = true;
				nonblank++;	
			}
		} else {
			if(x == '\n') {
				lines++;
				d = false;
			}
			if(x == '\n' || x == '\t' || x == ' ') {
				y = false;
			}
		}
		chars++;
	}
	
	// print values	
	printf("total number of characters: %d\n", chars);
	printf("total number of non-whitespace characters: %d\n", nonws);	
	printf("total number of lines: %d\n", lines);
	printf("total number of non-blank lines: %d\n", nonblank);
	printf("total number of words: %d\n", wc);

	return 0;

}
