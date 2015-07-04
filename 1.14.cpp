/*Составьте функцию concat, выполняющую конкатенацию произвольного количества строк:

char *concat(char **s, int n) 
{ 
        ... 
}
Здесь s – указатель на массив соединяемых строк, n – количество строк в массиве. Функция должна создавать в динамической памяти новую строку, размер которой равен суммарному размеру всех соединяемых строк, записывать в неё соединяемые строки друг за другом в том порядке, в котором они перечислены в массиве, и возвращать указатель на новую строку.
Программа concat.c, демонстрирующая работоспособность функции concat, должна считывать со стандартного потока ввода количество строк и сами соединяемые строки и выводить в стандартный поток вывода результирующую строку.
Пример входных данных программы:

4
One,
two,
three,
and four

Для этих данных программа должна выводить в стандартный поток вывода строку

One,two,three,and four */

#include <stdio.h>
#include <string.h>

char *concat ( char **s, int n) {
	int stringLength = 0;
	for ( int i = 0; i < n; i++)
		stringLength += strlen ( s[i] );

	char *answer = new char[stringLength];
	for ( int i = 0; i < n; i++)
		strcat ( answer, s[i]);

	return answer;
}


int main() {
	int number = 0;
	char **myString;

	printf ("Put the numbers of your strings:\n");
	scanf ("%d", &number);
	myString = new char*[number];
	for ( int i = 0; i < number; i++) {
		myString[i] = new char[20];
	}

	printf ("Put your lines:\n");
	getchar();
	for ( int i = 0; i < number; i++) {
		gets ( myString[i]);
	}

	myString[0] = concat ( myString, number);
	printf("%s\n", myString[0]);
	return 0;
}