#include <stdio.h>

int wcount (char *s) {
	int numberWords = 0;

	while (*s != '\0') {
		if (*s == ' ') while ( (*s == ' ') && (*s != '\0') ) s++;
		if ((*s != ' ') && (*s != '\0')) { 
			while ( (*s != ' ') && (*s != '\0') ) s++;
			numberWords++;
		}
	}
	return numberWords;
}

int main() {

	char *string = new char;
	int num = 0;

	printf ("Put your string:\n");
	gets(string);
	
	num = wcount(string);
	printf ("WordsNumber is:%d\n", num);
	return 0;
}