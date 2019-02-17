#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
 char str[20];
 printf("Enter a string");
 scanf("%20s",&str); //scanf doesn't know array size and accept more values than the size of array and cause unexpected behaviour 
 printf("%s",str);
}
