#include <stdio.h>
#include <math.h>
  int main() 
  {
  	int i,j,s;
  	for(j=-8;j<=8;j++)
  	{
  		for(s=1;s<=abs(j);s++)
  		printf("  ");
  		for(i=1;i<=(9-abs(j));i++)
            { printf("*   ");}
             printf("\n");
  	}
  	return 0;
  }
