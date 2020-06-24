/*
Can you code this challenge?

Title: Vigen�re Cipher
Difficulty: Intermediate

Make a program to accept some plaintext and a key from the user and use them to perform a Vigen�re Cipher and output the result.

More info on Vigen�re Ciphers: https://en.m.wikipedia.org/wiki/Vigen�re_cipher

Bonus points: Give the user a message if their input is invalid (empty/just numbers/etc)
*/

#include <stdio.h>
#include <string.h>
int main()
{
	char msg[1000],key[1000],gkey[1000],emsg[1000];
	printf("Please enter the message.(ONLY IN BLOCK LETTERS)");
	scanf("%s",msg);
	printf("Please enter the key to encrypt the message.(IN BLOCK LETTERS)");
	scanf("%s",key);
	int i,j;
	for(i=0;i<strlen(msg);)
	{
		for(j=0;j<strlen(key);j++)
		{
			if(i==strlen(msg))
			break;
			gkey[i]=key[j];
			i++;
		}
	}
	for(i=0;i<strlen(msg);i++)
	{
		j=(msg[i]-65)+gkey[i];
		if(j>90)
		j=j-26;
		emsg[i]=j;
	}
	printf("The encrypted message is: %s",emsg);
}