/*
Can you code this challenge?

Title: Disemvoweler
Difficulty: Intermediate

Make a program that removes every vowel and whitespace found  in a string. 
It should output the resulting disemvoweled string with the removed vowels 
concatenated to the end of it. For example 'Hello world' outputs 'hllwrld eoo'.
*/

#include<stdio.h>
#include<string.h>
int main()
{
	char str[20],str2[20];
	int i=0,j=0;
	printf("enter the string: ");
	gets(str);
	while(str[i]!='\0')
	{
		if(str[i]!='i' && str[i]!='a' && str [i]!='e' && str[i]!='o' && str[i]!='u' && str[i]!=' ')
		printf("%c",str[i]);
		else if(str[i]!=' ')
		{str2[j]=str[i];++j;}
		i=i+1;
	}
	str2[j]='\0';
	printf(" %s",str2);
}