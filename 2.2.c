/*В классической сортировке втавками для вставки элемента в отсортированную часть последовательности выполняется сравнение элемента со всеми членами
отсортированной части до тех пор,
пока для него не будет найдено место, то есть переменная loc (см. алгоритм в лекциях) уменьшается на единицу.
Метод Шелла является модификацией сортировки вставками, в которой переменная loc уменьшается на некоторое число d ≥ 1. 
При этом фактически сортировка выполняется несколько раз для всё меньших и меньших значений d до тех пор, пока d не станет равно 1.
Составьте функцию shsort, выполняющую сортировку массива строк методом Шелла. Функция shsort должна быть объявлена как

void shsort(char **a, int n) 
{ 
        ... 
}
В качестве параметров функция shsort принимает указатель на начало массива строк и количество строк в массиве.
Значения расстояния d в ходе работы программы должны образовывать последовательность Фибоначчи (естественно, записанную задом наперёд).
Итоговую программу, содержащую как функцию shsort, так и функцию main, демонстрирующую работоспособность функции shsort, нужно назвать shsort.c. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OF_LINES 5

void shsort (char **a, int n){
	int fib[5] = { 8, 5, 3, 2, 1 };
	int step = 0;
	char temp;
	int size = strlen(*a);
	for (int z = 0; z < 5; z++) {
		step = fib[z];
		for (int c = 0; c < n; c++) {
		int j = 0;
		int size = strlen(a[c]);

		for (int i = 1; (i < size) && ((i*step) < size); i++) {
			temp = a[c][i*step];
			for (j = step*(i-1); (j >= 0) && (a[c][j] > temp); j -= step)
				a[c][j+step] = a[c][j];
			a[c][j+step] = temp;
			} 
		}
	}
	return;
}

int main() {

	char **array = (char**)malloc(sizeof(char*)*NUM_OF_LINES);
	for (int i = 0; i < NUM_OF_LINES; i++) {
		array[i] = (char*)malloc(sizeof(char)*20);
		gets(array[i]);
	}
	shsort(array, NUM_OF_LINES);
	
	printf("Your new array:\n");
	for (int i = 0; i < NUM_OF_LINES; i++) 
		printf ("%s \n", array[i]);
	
	return 0;
}