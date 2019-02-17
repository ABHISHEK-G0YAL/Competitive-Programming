#include <stdio.h>
#include <string.h>
int main()
{
	int max,min,guess;
	char response[10];
	printf("Think of a number in your mind.\n\n");
	printf("Enter the range in which your number lies.\n");
	scanf("%d %d",&min,&max);
	while(1>=0)
	{
		guess=(rand()%((max-min+1)))+min;
		printf("Ok now I am going to guess your number.\n\n");
		printf("If the number I guess is lower than your number type \"low\".\n");
		printf("If the number I guess is higher than your number type \"high\".\n");
		printf("If the number I guess is equal to your number type \"equal\".\n");
		printf("\nThe number I guessed is %d\n",guess);
		printf("\nPlease enter your response\n");
		scanf("%s",&response);
		printf("\n\n\n");
		if(strcmp(response,"low")==0)
		min=guess+1;
		else if(strcmp(response,"high")==0)
		max=guess-1;
		else if(strcmp(response,"equal")==0)
		break;
		else
		printf("Please enter correct response\n\n");
	}
	return 0;
}
/*
Can you code this challenge?

Title: Guess the Number
Difficulty: Intermediate

Your program asks the user to guess and number and 
keep it in their head. It then asks the user to input 
a range that would dictates the maximum and minimun 
range your program should guess the number from. If 
your program guesses too high or too low, the user 
should be able to input "too high" or "too low" to 
notify you to fix your guess.
*/	
