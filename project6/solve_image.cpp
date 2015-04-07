#include <iostream>
#include <stdio.h>
#include <string.h>
#include "image_to_array.h"

using namespace std;

int main(int argc, char* argv[]) {

	char* filename;

	ImageData pre;
	ImageData post;
	
	if(argc == 2) {
		filename = new char[strlen(argv[1])];
		strncpy(filename, argv[1], strlen(argv[1]));
	} else {
		printf("No command line argument provided");
	}	

	pre = image_to_array(filename);

	post.width = pre.width;
	post.height = pre.height;

	post.data = new unsigned char*[post.height];

	for(int i = 0; i < post.height; i++) {
		post.data[i] = new unsigned char[post.width];
	}	

	for(int i = 0; i < pre.height; i++) {
		for(int x = 0; x < pre.width; x++) {
			if(pre.data[i][x] == 0) {
				pre.data[i][x] = 255;
			} else if(pre.data[i][x] == 255) {
				pre.data[i][x] = 0;
			}
			
			post.data[i][x] = pre.data[i][x];
		}
	}

	array_to_image(post, "solved image");



	cv::waitKey(0);
	return 0;

		
	
}
