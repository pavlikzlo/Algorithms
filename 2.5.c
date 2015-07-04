/*Составьте функцию hsort, выполняющую пирамидальную сортировку произвольного массива. 
Объявление функции hsort должно быть выполнено по аналогии с функцией qsort:

void hsort(void *base, size_t nel, size_t width, 
        int (*compare)(const void *a, const void *b)) 
{ 
        ... 
}
В качестве параметров функция hsort принимает указатель на начало массива base,
 количество элементов массива nel, размер одного элемента width и указатель на 
 функцию сравнения compare.
Итоговую программу, содержащую как функцию hsort, так и функцию main, 
демонстрирующую работоспособность функции hsort, нужно назвать hsort.c. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int IntCompare (const void *a,const void *b)
{
	int *a_i = (int*)a;
	int *b_i = (int*)b;
	return (*a_i > *b_i) ? 1 : 0;
}

int DoubleCompare (const void *a,const void *b)
{
	double *a_d = (double*)a;
	double *b_d = (double*)b;
	return (*a_d > *b_d) ? 1 : 0;
}

int CharCompare (const void *a,const void *b)
{
	char *a_c = (char*)a;
	char *b_c = (char*)b;
	return (*a_c > *b_c) ? 1 : 0;
}

void swap (void *a, void *b, size_t width)
{
	char *a_c = (char*)a;
	char *b_c = (char*)b;
	char *temp = (char*)malloc(30);
	for (int i = 0; i < width; i++) {
		temp[i] = a_c[i];
		a_c[i] = b_c[i];
		b_c[i] = temp[i];
	}
}

void heapify (void *array, size_t nel, size_t i, size_t width,
			  int (*compare)(const void *a, const void *b))
{
	char *A = (char*)array;
	size_t left = 0, right = 0, temp = 0, j = 0;
	while (1) {
		left = 2*i + 1;
		right = left + 1;
		j = i;
		if ((left < nel) && compare(A + left*width, A + i*width))
			i = left;
		if ((right < nel) && compare(A + right*width, A + i*width))
			i = right;
		if (i == j)
			break;
		swap (A + i*width, A + j*width, width);
	}
	return;
}

void BuildHeap (void *array, size_t nel, size_t width,
				int (*compare)(const void *a, const void *b))
{
	int i = nel/2 - 1;
	while (i >= 0) {
		heapify (array, nel, i, width, compare);
		i--;
	}
}


void hsort(void *base, size_t nel, size_t width,
		   int (*compare)(const void *a, const void *b))
{
	char *array = (char*)base;
	int i = nel - 1;
	BuildHeap (array, nel, width, compare);
	while (i != 0) {
		swap(array, array + width*i, width);
		BuildHeap(array, i, width, compare);
		i--;
	}
}


int main() {

	int A[13] = {1, 3, 5, 8, 2, 10, 7, 10, 15, 13, 9, 7, 6};
	double B[10] = {10.2, 9.1, 1.1, 0.5, 3.7, 5.1, 4.0, 9.8, 11.2, 15.1};
	char C[8] = { 'x', 'b', '-', 'k', 'l', 'i', 'a', 'w'};
	//hsort(A, sizeof(A)/sizeof(int), sizeof(int), IntCompare);
	//hsort(B, sizeof(B)/sizeof(double), sizeof(double), DoubleCompare);
	hsort(C, sizeof(C)/sizeof(char), sizeof(char), CharCompare);
	printf("Your array:\n");
	for (int i = 0; i < 8; i++)
		printf("%c ", C[i]);
	printf("\n");
	return 0;
}