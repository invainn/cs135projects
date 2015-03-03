#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int n);
void readArray(int *array, int n);
void bubbleSort(int *array, int n);
void selectionSort(int *array, int n);
void quickSort(int *array, int base, int count);
void swap(int &food, int &bars);

int main(int argc, char* argv[]) {
	
	int count = 1000000;
	if(argc == 2) {
		count = atoi(argv[1]);
	}	

	int input[count];

	readArray(input, count);
	//bubbleSort(input, count);
	//quickSort(input, 0, count);
	selectionSort(input, count);
	printArray(input, count);	
}
	
void printArray(int array[], int n) {
	for(int i = 0; i < n; i++) {
		printf("%d\n", array[i]);
	}
}

void readArray(int array[], int n) {
	int temp = 0;

	for(int i = 0; i < n; i++) {
		scanf("%d", &temp);
		array[i] = temp;
	}
}

void bubbleSort(int array[], int n) {
	bool hasSwapped = true;
	
	while(hasSwapped) {
		hasSwapped = false;
		for(int i = 0; i < n-1; i++) {
			if(array[i] > array[i+1]) {
				swap(array[i], array[i+1]);
				hasSwapped = true;
			}
		}
	}
}

void selectionSort(int array[], int n) {
	int min = 0;

	for(int i = 0; i < n-1; i++) {
		min = i;
		for(int x = i + 1; x < n; x++) {
			if(array[x] < array[min]) {
				min = x;
			}
		}	
		if(min != i) {
			swap(array[i], array[min]);
		}
	}
}

void quickSort(int array[], int base, int count) {
	int min = base;
	int max = count;
	int pivot = array[(min + max)/2];

	while(min <= max) {
		while(array[min] < pivot) {
			min++;
		}
		while(array[max] > pivot) {
			max--;
		}
		if(min <= max) {
			swap(array[min], array[max]);
			min++;
			max--;
		}
	}

	if(base < min) {
		quickSort(array, base, max);
	}
	if(min < count) {
		quickSort(array, min, count);
	}
}

void swap(int &food, int &bars) {
	int temp = food;
	food = bars;
	bars = temp; 
}
