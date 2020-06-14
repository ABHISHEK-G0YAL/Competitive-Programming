#include <stdio.h>
  int main() 
  {
  	int i,j,s;
  	for(j=1;j<=8;j++)
  	{
  		for(s=1;s<=(8-j);s++)
  		printf("   ");
  		for(i=1;i<=j;i++)
            { printf("*");}
             printf("\n");
  	}
  	return 0;
  }
