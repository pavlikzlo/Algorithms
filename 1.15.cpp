/*Составьте программу pstring.c, которая определяет, является ли введённая из стандартного потока ввода строка периодической.
Периодической называется строка, которую можно представить в виде dd…d, где d – некоторая подстрока.
Пример входных данных программы:

abcdabcdabcd

Для этих данных программа выводит сообщение

yes

В случае, если введённая строка не является периодической, программа должна выводить сообщение

no
*/
#include <stdio.h>
#include <string.h>

char *BreakString (char *s, int n) {
	char *newS = new char[n];
	for ( int i = 0; i < n; i++)
		newS[i] = s[i];
	return newS;
}

int main() {
	char *s = new char[50];
	int stringLength = 0, temp = 0;

	printf ("Put your string:\n");
	gets(s);
	stringLength = strlen(s);

	for ( int i = 1; i < ((stringLength/2) + 1); i++) {
		if ((stringLength % i) == 0) {
			int count = 0;
			for ( int j = 1; j < (stringLength / i); j++) 
				if ( !strcmp( BreakString ( s, i), BreakString ( s + j*i, i) ) ) count++;

			if ( count == ((stringLength / i) - 1) ) 
			{
				printf("yes\n");
				temp = 1;
				break;
			}
		}
	}

	if (!temp) printf("no\n");
	return 0;
}