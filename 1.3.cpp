#include <stdio.h> 
#include <math.h>

#define NUM 600851475143 

int isSimple (int x) {
	for (int i = ceil(sqrt(x)); i > 2; i--){
		if ((i%2 != 0) && (isSimple(i) == 1)) {
			if (x%i == 0) return 0;
			else return 1;
			} 
	} 
}

int main(){

	for (int i = ceil(sqrt(NUM)); i > 2; i--) {
		if ((i%2 != 0) && (isSimple(i) == 1)) {
			if (NUM%i == 0) {
				printf("The most simple number that divides your num is:%d\n", i);
				break;
			}
		}
	}

	return 0;
}