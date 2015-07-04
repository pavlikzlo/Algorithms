/*Пусть элементы матрицы A размера n×m упорядочены по возрастанию по строкам и столбцам, то есть:
A[i,j]<A[i,k], если j < k;
A[i,j]<A[k,j], если i < k.
Нужно составить программу descend.c, выполняющую поиск элемента матрицы, равного заданному числу x.
Программа должна считывать со стандартного потока ввода число x, размеры матрицы и значения её элементов,
и выводить в стандартный поток вывода индексы (i,j) найденного элемента. В случае, если такого элемента не окажется, программа должна выводить следующее сообщение:

not found

Пример входных данных программы:

28
3 5
10 11 12 13 14
12 18 20 25 30
13 19 21 28 35

Для этих данных программа должна выводить в стандартный поток вывода индексы

2 3

Действительно, элемент 28 расположен во второй строке и третьем столбце матрицы (будем считать, что строки и столбцы нумеруются с нуля).
Алгоритм поиска, реализуемый программой, должен быть составлен таким образом, чтобы число x сравнивалось не более, чем с m + n элементами матрицы.*/



#include <stdio.h>

void SearchNum (int **array, int key, int n, int m) {
	int firstM = 0; n--; m--;
	while ((n >= 0) && (firstM <= m)) {
	if (array[n][firstM] > key) n--;
	else if (array[n][firstM] < key) firstM++;
		 else {
		 	printf ("Your index is: %d %d\n", n, firstM);
		 	return;	
		}
	}
	printf ("There is no key!\n");
	return;
}

int main() {
	
	int n = 0, m = 0, number = 0;

	printf ("Enter the number:\n");
	scanf ("%d", &number);

	printf ("Put size of your matrix:\n");
	scanf ("%d %d", &n, &m);

	int **array = new int*[n];
	for ( int i = 0; i < n; i++)
		array[i] = new int[m];

	printf ("Put elements to your array:\n");
	for ( int i = 0; i < n; i++) {
		for ( int j = 0; j < m; j++)
			scanf ("%d", &array[i][j]);
	}

	printf ("Your array is: \n");
	for ( int i = 0; i < n; i++)
	{
		for ( int j = 0; j < m; j++)
			printf ("%d ", array[i][j]);
		printf("\n");
	}
	printf("\n");

	SearchNum (array, number, n, m);
	return 0;

}