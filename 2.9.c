/*Составьте программу datesort.c, осуществляющую сортировку последовательности дат 
по возрастанию. В программе должен быть реализован алгоритм поразрядной сортировки,
 адаптированный для случая, когда ключи представляются в системе счисления с 
 основаниями, зависящими от разряда.
В программе сортируемая последовательность должна быть представлена в виде массива
структур Date:

struct Date { 
    int Day, Month, Year; 
};
Поле Day может принимать значения от 1 до 31, поле Month – от 1 до 12, 
а поле Year – от 1970 до 2030.
Последовательность дат считывается из стандартного потока ввода. 
При этом в самом начале считывается общее количество дат,
а каждая дата представляется тройкой чисел

yyyy mm dd 

Например, если введена последовательность

5
2005 01 12
1977 02 01
1994 03 01
2004 02 29
1977 08 01

то программа должна выводить в стандартный поток вывода

1977 02 01
1977 08 01
1994 03 01
2004 02 29
2005 01 12 */

#include <stdio.h>
#include <stdlib.h>

#define YEAR_CORRECTION 1970

void DistribitionSort (char *array, int nel, int m)
{
	int *temp = (int*)malloc(sizeof(int)*m);
	int i = 0, j = 0, key = 0,index = 0, num = 0;
	
	while (i < nel) {
		temp[i] += 1;
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
			array[index] = j;
			index++;
		}
		j++;
	}
	return;
}

struct Date {
	int Day, Month, Year;
};

void PrintAllInf (struct Date *array, int number) {
	for (int i = 0; i < number; i++)
		printf("%d %d %d\n", array[i].Year, array[i].Month, array[i].Day);
	return;
}

int* NumToString (struct Date *array, int nel) {
	char *temp[] = (char*)malloc(sizeof(char)*nel);
	temp
}

void RadixSort (struc Date *array, int nel) {

}

int main() {
	int num_of_el = 0;
	printf("Put number of your structers:\n");
	scanf ("%d", &num_of_el);
	struct Date date_array[num_of_el];
	printf("Put your information: Day, Month, Year.\n");
	for (int i = 0; i < num_of_el; i++)
		scanf ("%d %d %d\n", &date_array[i].Year, &date_array[i].Month, &date_array[i].Day);
	PrintAllInf (date_array, num_of_el);
	return 0;
}