#include <stdio.h>
#include <string.h>
int main()
{
	char input[20];int i,x=0,y=0;
	scanf("%20s",input);
	for(i=0;i<strlen(input);i++)
	{
		if(i%2==0)
		continue;
		else if(input[i]=='N')
		y=y+(input[i-1]-'0');
		else if(input[i]=='S')
		y=y-(input[i-1]-'0');
		else if(input[i]=='E')
		x=x+(input[i-1]-'0');
		else if(input[i]=='W')
		x=x-(input[i-1]-'0');
		else
		printf("Invalid Input");
	}
	printf("(%d,%d)",x,y);
}
