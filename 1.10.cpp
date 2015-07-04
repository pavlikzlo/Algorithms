#include <stdio.h>

int search (int *a, int nel, int k) {
	if ( (a[0] <= k) && (a[nel - 1] >= k)) {
		int mid = ((nel - 1) / 2);
		if (a [mid] > k) return search (a, mid, k);
		if (a [mid] < k) return (mid + 1 + search (&a[mid + 1], nel - mid - 1, k));
		if (a[mid] == k) return (mid + 1);
	}
	return -1 ;

}

int main() {
	int nel = 0, key = 0;
	int index = 0;

	printf ("Put size of your array:\n");
	scanf("%d", &nel);

	printf ("Put your key:\n");
	scanf ("%d", &key);

	int *array = new int[nel];
	printf ("Put the numbers to your array:\n");
	for (int i = 0; i < nel; i++) {
		scanf("%d", &array[i]);
	}

	index = search (array, nel, key);
	printf ("Check:%d\n", index);
}