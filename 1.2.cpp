#include <stdio.h>

int main(){
	int sum = 0, fib1 = 1, fib2 = 1, fib = 0;
	while (fib <= 4000000) {
		fib = fib2 + fib1;
		if (fib%2 == 0) sum += fib;
		fib2 = fib1;
		fib1 = fib;
	}
	printf ("Your sum is: %d\n", sum);
	return 0;
}