#include <stdio.h>
#include <math.h>

int main (){
	for (int x = 0; x < 998; x++)
		for (int y = x; y < 998 - x; y++)
			for (int z = y; z < 998 - y; z++){
			if ((pow(x,2) + pow(y,2)) == pow(z,2))
				if ((x + y + z) == 1000){
					printf("Hey you:%d %d %d\n",x,y,z);
					return 1;
				}
			}
}