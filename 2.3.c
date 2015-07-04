/*В классической сортировке пузырьком проход по сортируемой последовательности осуществляется 
всегда в одном направлении. Существует модификация алгоритма,
в которой чередуются проходы по последовательности слева направо и справа налево.
Составьте программу bsort.c, осуществляющую сортировку
массива целых чисел в порядке убывания количества разрядов в десятичной записи числа.
 Программа должна реализовывать модифицированный двунаправленный пузырьковый алгоритм.
Сортируемая последовательность должна передаваться в программу через аргументы командной строки.*/
#include <stdlib.h>
#include <stdio.h>


 int compare (int a, int b) {
 	int count2 = 0, count1 = 0;
 	while (a%10 != 0) {
		count1++;
		a = a/10;
	}
 	while (b%10 != 0) {
		count2++;
		b = b/10;
	}
 	return (count1 > count2) ? 1 : 0;
 }

 void sortBubble (int *array, int n, int (*compare)(int a, int b)){
 	int exchange = 1, temp = 0;
 	do {
 		exchange = 0;
 		for (int i = 1; i < n; i++)
 			if (compare(array[i-1], array[i])) {
 				temp = array[i];
 				array[i] = array[i-1];
 				array[i-1] = temp;
 				exchange = 1;
 			}
 		for (int i = n - 1; i >= 0; i--) 
 			if (compare(array[i-1], array[i])) {
 				temp = array[i];
 				array[i] = array[i-1];
 				array[i-1] = temp;
 				exchange = 1;
 			}
 	}
 	while (exchange);
 }
 
 int main(){
 	int n = 0;

 	printf("Put your size of array:\n");
 	scanf("%d", &n);
 	int *array = (int*)malloc(sizeof(int)*n);
 	printf("Put your numbers:\n");
 	for (int i = 0; i < n; i++)
 		scanf("%d", &array[i]);

 	sortBubble (array, n, compare);

 	printf("Your array:\n");
 	for (int i = 0; i < n; i++)
 		printf("%d ", array[i]);
 	printf("\n");
 	return 0;
 }