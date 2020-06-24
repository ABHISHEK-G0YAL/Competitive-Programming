#include <stdio.h>
#include <math.h>
void main()
{
	char x,y;
	printf("Enter 2 Characters\n");
	scanf("%c %c",&x,&y);
	printf("x=%c y=%c \n",x,y);
	printf("ASCII values are  %d,%d\n",x,y);
	printf("Enter 2 decimal numbers\n");
	double a,b,c,d,e,sq;
	scanf("%lf %lf",&a,&b);
	printf("A=%lf ,B=%lf \n",a,b);
	c=a+b;
	printf("Sum of the numbers = %lf \n",c);
	d=a*b;
	printf("Product of the numbers = %lf \n",d);
	e=a-b;
	printf("Difference of the numbers = %lf \n",e);
	sq=sqrt(d);
	printf("Sqrt of the product is = %lf \n",sq);
}