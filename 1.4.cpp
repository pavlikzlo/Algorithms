#include <stdio.h>
#include <math.h>

int isPolindrom(int x, int y){
	if ((x%10) == (y/100)) 
		if (((x/10)%10) == ((y%100)/10))
			if ((x/100) == (y%10))
				return 1;
	else return 0; 
}

int main(){
	int num = 0,left = 0, right = 0;
	for (int i = 999; i >= 100; i--)
		for (int j = 999; j >= 100; j--){
			num = i * j;
			left = num / 1000;
			right = num % 1000;
			if (isPolindrom(left,right) == 1) {
				printf("Your num:%d\n", num);
				return 0;
				break;
			}
		}
}