#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int a,b,i,kind;
	printf("\n找出1~n的所有質數\nn:\n");
	scanf("%d",&a);
	
	printf("\n  2\n");
	for(b=3;b<=a;b++)
	{
		for(i=2;i<b;i++)
		{
			if(b%i==0)
				kind=1;		
		}
		if(kind==0)
			printf("  %d\n",b);
		kind=0;
	}
	printf("\n");
	system("pause");
	return 0;
}

