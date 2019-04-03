#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int i;
	system("color 2");
	while(1){
		i=rand();
		if(i%2==1)
			printf("1");
		else
			printf("0");
	}
	return 0;
}

