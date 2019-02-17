#include <stdio.h>
  int main() 
  {
  	int a,n,j;
  	scanf("%d",&n);
  	for(j=0;j<n;j++)
  	{
  		for(a=65+j;a>=65;a--)
  		{
  			printf("%c ",a);
  			}
  			printf ("\n");
  			}
  	return 0;
  	 }
