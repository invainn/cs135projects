#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *array, int key, int n);
int binarySearch(int *array, int key, int chicken);
int recursiveBinarySearch(int *array, int key, int min, int max);
void readArray(int *array, int n);

int main(int argc, char* argv[]) {

	int key = 0;
	int n = 0;
	
	if(argc == 3) {
		key = atoi(argv[1]);
		n = atoi(argv[2]);
	}
	
	printf("key = %d and array count = %d\n", key, n);
	
	int arry[n];	
	
	readArray(arry, n);

	for(int i = 0; i < n; i++) {
		printf("%d\n", arry[i]);
	}

	// linear search aka never using this unless the array is small
	//int result = linearSearch(arry, key, n);

	// regular iterative binary search
	//int result = binarySearch(arry, key, n);

	// big boy recursive binary search
	int result = recursiveBinarySearch(arry, key, 0, n);

	if(result == -999999) {
		printf("Unable to find number\n");
		return 0;
	}

	printf("%d is found at index %d\n", key, result);	

	return 0;
}

int binarySearch(int array[], int key, int chicken) {
	int min = 0;
	int max = chicken;
	while(max >= min) {
		int mid = (min + max)/2;
		if(array[mid] == key) {
			return mid;
		} else if(array[mid] < key) {
			min = mid + 1;
		} else {
			max = mid - 1;
		}
	}	
	return -999999;
}

void readArray(int array[], int n) {
	int temp = 0;
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &temp);
		array[i] = temp;	
	}
}

int recursiveBinarySearch(int array[], int key, int min, int max) {
	if(max >= min) {
		int mid = (min + max)/2;

		if(array[mid] == key) {
			return mid;
		} else if(array[mid] < key) {
			return recursiveBinarySearch(array, key, mid + 1, max);
		} else {
			return recursiveBinarySearch(array, key, min, mid - 1);
		}
	}
	return -999999;
}

int linearSearch(int array[], int key, int n) {
	for(int i = 0; i < n; i++) {
		if(array[i] == key) {
			return i;
		}
	} 
	return -999999;
}
