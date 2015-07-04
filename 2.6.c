/*Составьте программу msort.c, осуществляющую сортировку массива целых чисел в 
порядке
 возрастания.
В программе должен быть реализован алгоритм сортировки слиянием, рекурсивную функцию 
которого нужно модифицировать таким образом, чтобы для последовательностей длиной 
меньше m выполнялась сортировка вставками.
Сортируемая последовательность должна порождаться программой автоматически с помощью
 датчика псевдослучайных чисел (см. функцию rand() из стандартной библиотеки языка C).
Число m, а также размер последовательности n должны передаваться в программу 
через аргументы командной строки. */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void merge (int *array, size_t k, size_t l, size_t m, int *buf)
{
	int index = k;
	int count = k;
	int z = l + 1;
	while (index <= m) {
		if (((array[k] <= array[z]) && (k < (l + 1))) || (z > m))
		{
			buf[index] = array[k];
			index++;
			k++;
		}
		else if (z <= m) {
			buf[index] = array[z];
			index++;
			z++;
		}
	}
	for (int i = count; i <= m; i++)
		array[i] = buf[i];
}

void InsertSort (int *array, int low, int high) {
	for (int i = low + 1; i <= high; i++){
		int temp = array[i];
		int j = 0;
		for ( j = i - 1; ((temp < array[j]) && (j >= low)); j--) 
			array[j + 1] = array[j];
		array[j + 1] = temp;
	}
}

void mergeSortRec (int *array, int low, int high, int *buf, int m)
{
	if (high > low) {
		if ((high - low) > m) {
			int mid = (high - low) / 2 + low;
			mergeSortRec(array, low, mid, buf, m);
			mergeSortRec(array, mid + 1, high, buf, m);
			merge(array, low, mid, high, buf);
		}
		else 
			InsertSort(array, low, high);
	}
}

void mergeSort (int *array, int nel, int *buf)
{
	mergeSortRec (array, 0, nel-1, buf, 2);
}

int main (int argc, char *argv[])
{
	int nel = atoi(argv[1]);
	int m = atoi(argv[2]);
	int *array = (int*)malloc(sizeof(int)*nel);
	for (int i = 0; i < nel; i++)
		array[i] = rand()%100000;

	printf("Your array is:\n");
	for (int i = 0; i < nel; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	int *buf = (int*)malloc(sizeof(int)*20);
	//merge (A, 3, 5, 8, buf);
	mergeSort(array, 10, buf);
	//InsertSort (A, 0, 10);
	printf("Your combined array is:\n");
	for (int i = 0; i < 10; i++)
		printf("%d ",array[i]);
	printf("\n");
	return 0;
}