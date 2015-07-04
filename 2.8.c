/*Составьте программу dsort.c, осуществляющую сортировку латинских букв в строке 
в алфавитном порядке (размер строки – до миллиона букв). В программе должен быть 
реализован алгоритм сортировки распределением.
Например, если введена строка

encyclopedia

то программа должна выводить в стандартный поток вывода

accdeeilnopy

Строка вводится с клавиатуры, причём известно, что она содержит только
маленькие латинские буквы.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_CORRECT 97
void DistribitionSort (char *array, int nel, int m)
{
	int *temp = (int*)malloc(sizeof(int)*m);
	int i = 0, j = 0, key = 0,index = 0, num = 0;
	
	while (i < nel) {
		key = (int)array[i];
		temp[key - ASCII_CORRECT] += 1;
		i++;
	}

	i = 1;
	while (i < m) {
		temp[i] += temp[i-1];
		i++;
	}

	while (j <= m) {
		num = temp[j] - index;
		for (int i = 0; i < num; i++) {
			array[index] = (char)(j + ASCII_CORRECT);
			index++;
		}
		j++;
	}
}

int main()
{
	int m = 25;
	char *s = (char*)malloc(sizeof(char)*1000);
	printf("Put your string:\n");
	gets(s);

	DistribitionSort(s, strlen(s), m);
	printf("Your new string\n%s\n", s);
}