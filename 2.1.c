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
void DistribitionSort (char *array, int nel)
{
    int *temp = (int*)malloc(sizeof(int)*1000);
    int i = 0, j = 0, key = 0,index = 0;
    while (i < nel) {
        key = (int)array[i];
        temp[key] = temp[key] + 1;
        i++;
    }
    i = 0;
    while (i < nel) {
        temp[i] = temp[i] + temp[i-1];
        i++;
    }
    for(int i = 0; i < nel; i++)
    printf("%d ", temp[i]);
    while (j < nel) {
        array[j] = (char)temp[j];
        j++;
    }
    
}

int main()
{
    char *s = (char*)malloc(sizeof(char)*1000);
    printf("Put your string:\n");
    gets(s);
    
    DistribitionSort(s, strlen(s));
    printf("Your new string\n%s", s);
}