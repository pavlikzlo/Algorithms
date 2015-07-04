#include <stdio.h>

int CompareChar (const void *a, const void *b){

	return (*(char*)a > *(char*)b) ? 1 : 0;
}

int CompareLong (const void *a, const void *b){

	return (*(long*)a > *(long*)b) ? 1 : 0;
}

int CompareInt (const void *a, const void *b){

	return (*(int*)a > *(int*)b) ? 1 : 0;
}

int CompareMatrixInt (const void *a, const void *b){
	int countA = 0, countB = 0;

	for (int i = 0; i < 3; i++) {
		if ( *((int*)a + i) == 0 ) countA++;
		if ( *((int*)b + i) == 0 ) countB++;
		}
	return (countA > countB) ? 1 : 0;
}

int max (void *base, int nel, int width, int (*compare)(const void *a, const void *b));

int main () {
	long L[7] = { 8, 5, 9, 2, 10, 15, 0 }; 
	char C[7] = { 'Q', 'W', 'E', 'R', 'T', 'Y', 'Z' };
	int M[4][3] = { 
        {0, 2, 3}, {4, 5, 6}, {7, 0, 0}, {0, 0, 0} };
	int value = 0; 

	value = max (L, 7, sizeof(long), CompareLong);
	printf ("My check:%d\n", value);

	value = max (C, 7, sizeof(char), CompareChar);
	printf ("My check:%d\n", value);

	value = max (M, 4, sizeof(int)*3, CompareMatrixInt);
	printf ("My check:%d\n", value);
}

int max (void *base, int nel, int width, int (*compare)(const void *a, const void *b)) {
	char *temp = new char[nel*width];
	char *max = new char[width];
	temp = (char*)base;

	max = temp; 
	int index = 0;

	for (int i = 0; i < nel; i++) 
		if (compare((temp + i * width), max) == 1 ) {
			index = i;
			max = &temp[i * width];
		}
	return ++index;
}