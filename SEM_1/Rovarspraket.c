#include <stdio.h>
#include <string.h>
void main()
{
	char str[1000];int i;
	gets(str);
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]>='A' && str[i]<='Z')
		{
			if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')
			printf("%c",str[i]);
			else
			printf("%cO%c",str[i],str[i]);
		}
		else if(str[i]>='a' && str[i]<='z')
		{
			if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
			printf("%c",str[i]);
			else
			printf("%co%c",str[i],str[i]);
		}
		else
		printf("%c",str[i]);
	}
}
/*
Can you code this challenge?

Title: Rovarspraket
Difficulty: Intermediate

Rovarspraket which means "Robber's language" in Swedish is not very complicated. 
You take an ordinary word and replace the consonants with the consonant doubled 
with an 'o' between them. For example 'b' becomes 'bob', m becomes 'mom'. Vowels 
are left intact. Make a program that translates any length of string into Rovarspraket. 

For added difficulty, make it able to translate to and from Rovarspraket.
*/
