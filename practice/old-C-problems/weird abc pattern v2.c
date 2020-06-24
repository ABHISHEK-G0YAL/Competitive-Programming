/*
Enter number of rows to print
10

         A
        A A
       B A B
      B A A B
     C B A B C
    C B A A B C
   D C B A B C D
  D C B A A B C D
 E D C B A B C D E
E D C B A A B C D E
*/

#include <stdio.h>
  int main() 
  {
  	int a,b,n,j,x,s;
  	printf("Enter number of rows to print \n");
  	scanf("%d",&n);
  	for(j=0;j<=n;j++)
  	{
  		for(s=1;s<=n-j;s++)
  		{
  			printf(" ");
		}
  		x=j/2;
  		for(a=65+((j-x)-1);a>=65;a--)
  		{
  			printf("%c ",a);
  			}
  		for(b=65;b<65+x;b++)
  		{
  			if(j%2!=0)
  			{
  				b=b+1;
  				}
  			printf("%c ",b);
  			if(j%2!=0)
  			{
  				b=b-1;
  				}
  			}
  			printf ("\n");
  			}
  	return 0;
}