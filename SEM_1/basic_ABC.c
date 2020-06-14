#include <stdio.h>
  int main() 
  {
  	int a,j,s;
  	for(j=0;j<=6;j++)
  	{
  		for(s=1;s<=6-j;s++)
  		printf("  ");
  		for(a=65;a<=65+j;a++)
  		{
  		printf("%c ",a);
  		}
  		printf ("\n");
  	}
  	return 0;
  }
