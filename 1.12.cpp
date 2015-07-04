#include <stdio.h>

int **transpose ( int **a, int m, int n) {
	int **b = new int*[n];
	for ( int i = 0; i < n; i++)
		b[i] = new int[m];

	for ( int i = 0; i < m; i++)
		for ( int j = 0; j < n; j++)
			b[j][i] = a[i][j];

	return b;
}

int main() {
	int m = 0, n = 0;
	printf ("Put size of your matrix:\n");
	scanf ("%d %d", &m, &n);

	int **array = new int*[m];
	int **answer;
	for ( int i = 0; i < m; i++)
		array[i] = new int[n];

	printf ("Put the elements to your matrix:\n");
	for ( int i = 0; i < m; i++) {
		//printf("\n");
		for ( int j = 0; j < n; j++)
			scanf ("%d", &array[i][j]);
	}

	answer = transpose ( array, m, n);
	printf ("Your transpose array:");
	for ( int i = 0; i < n; i++) {
		printf ("\n");
		for ( int j = 0; j < m; j++)
			printf("%d ", answer[i][j]);
	}
	printf("\n");


}