#include<stdio.h>
#include<stdlib.h> 
#include<math.h>
int main(void){
	double a,b,c;
	printf("\nsolve ax^2 +bx +c \n\n");
	printf("¿é¤Ja,b,c:\n\n");
	scanf("%lf %lf %lf",&a,&b,&c);
	if(b*b-4*a*c>0)
		printf("\n  two distinct roots:\n\n  %f\n  %f\n\n",
			(-b+sqrt(b*b-4*a*c))/2*a,(-b-sqrt(b*b-4*a*c))/2*a);
	else if(b*b-4*a*c==0)
		printf("\n  repeat root:\n\n  %f\n\n",-b/2/a);
	else
		printf("\n  no real root\n\n");
	system("pause");	
	return 0;
}
