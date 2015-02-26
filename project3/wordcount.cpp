#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

	// boolean y is used as a switch to be false when a word is counted
	// and to be true when if it is not a word
	bool y = false;
	bool d = false;

	// int x is used to retrieve the next char from the file
	char x;
	char dictx;
	int chars = 0;
	int nonws = 0;
	int lines = 0;
	int wc = 0;
	int nonblank = 0;
	int dictwc = 0;

	string temp;
	string tempdict;

	// object pointer file grabs the file name and reads it
	FILE* file = fopen(argv[1], "r");
	FILE* dict = fopen("words", "r");
	

	if(file == NULL || dict == NULL){
		printf("Could not open file\n");
		return 0;
	}

	// loops until end-of-file	
	while((x = getc(file)) != EOF) {
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
			// append the value of x to temp
			temp += x;
		} else {
			if(x == '\n') {
				lines++;
				d = false;
			}
			if(x == '\n' || x == '\t' || x == ' ') {
				y = false;
			}
			while((dictx = getc(dict)) != EOF) {
				if(dictx != '\n') {
					tempdict += dictx;	
				} else {
					// cout << temp << "\n" << tempdict << "\n\n";
					if((temp.compare(tempdict)) == 0) {
						tempdict.clear();
						temp.clear();
						dictwc++;
						break;
					} else {
						tempdict.clear();
					}
				}
			}
			temp.clear();
			clearerr(dict);
			rewind(dict);
		}
		chars++;
	}
	
	// print values	
	printf("total number of characters: %d\n", chars);
	printf("total number of non-whitespace characters: %d\n", nonws);	
	printf("total number of lines: %d\n", lines);
	printf("total number of non-blank lines: %d\n", nonblank);
	printf("total number of words: %d\n", wc);
	printf("total number of dictionary words: %d\n", dictwc);

	return 0;

}
