/*Составьте программу qsort.c, осуществляющую сортировку массива целых чисел
в порядке возрастания.
В программе должен быть реализован алгоритм быстрой сортировки, рекурсивную 
функцию которого нужно модифицировать таким образом, чтобы для последовательностей 
длиной меньше m выполнялась сортировка прямым выбором.
Сортируемая последовательность должна порождаться программой автоматически с помощью
датчика псевдослучайных чисел (см. функцию rand() из стандартной библиотеки языка C).
Число m, а также размер последовательности n должны передаваться в программу через 
аргументы командной строки.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void SelectSort (int *array, int low, int high) 
{
	int *max, temp = 0;
	while (high > low) {
		max = array + low;
		for (int j = low + 1; j <= high; j++)
			if (max[0] < array[j])
				max = array + j;
		temp = array[high];
		array[high] = max[0];
		max[0] = temp;
		high--;
	}

}

int partition (int *array, int low, int high) {
	int i = low, temp = 0, j = low;
	while (j < high) {
		if (array[j] < array[high]) {
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
		}
		j++;
	}
	temp = array[i];
	array[i] = array[high];
	array[high] = temp;
	return i;
}

void QsortRec (int *array, int low, int high, int m)
{
	if (low < high) {
		if ((high - low + 1) > m) {
		int place = partition(array, low, high);
		QsortRec(array, low, place - 1, m);
		QsortRec(array, place + 1, high, m);
	}
		else SelectSort(array, low, high);
	}
}

void Qsort(int *array, int nel, int m)
{
	QsortRec(array, 0, nel-1, m);
}

int main(int argc, char *argv[])
{
	int m = atoi(argv[2]), nel = atoi(argv[1]);
	srand(time(NULL));
	int *array = (int*)malloc(sizeof(int)*nel);
	for (int i = 0; i < atoi(argv[1]); i++)
		array[i] = rand()%100;

	printf("Your array is:\n");
	for (int i = 0; i < atoi(argv[1]); i++)
		printf("%d ", array[i]);
	printf("\n");

	int A[10] = {178, 3, 4, 10, 40, 54, 7, 19, 20, 1};
	Qsort(array, nel, m);

	for (int i = 0; i < 10; ++i)
		printf("%d ",array[i]);
	printf("\n");

	return 0;
}