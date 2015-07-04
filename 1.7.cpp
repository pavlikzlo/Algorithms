#include <stdio.h>

void reverse (void *base, int nel, int width) {
	for (int i = 0; i < (nel/2); i++){
		char *temp = new char;
		base = (char*)base;

		for (int j = 0; j < width; j++) temp[j] = base[i*width + j];
		base[i*width] =base[width*(nel - i - 1)];
		for (int j = 0; j < width; j++) base [width*(nel - i - 1) + j)] = temp[j];

		delete temp;
	}
}

int main() {
	long L[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }; 
	char C[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' }; 
	int M[5][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15} };

	reverse (L, 15, sizeof(long));
	for (int i = 0; i < 15; i++)
	printf ("Your array:%ld \n", *(L + i));

	reverse (C, 10, sizeof(char));
	for (int i = 0; i < 10; i++)
	printf ("Your array:%c \n", *(C + i));

	reverse (M, 15, sizeof(int));
	for (int i = 0; i < 15; i++)
	printf ("Your array:%d \n",*(*M + i));


	return 0;
}