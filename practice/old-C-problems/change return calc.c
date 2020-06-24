/*
Can you code this challenge?

Title: Change Return Program
Difficulty: Beginner

Develop a program that has the user enter the cost of an item and then 
the amount the user paid for the item. Your program should figure out 
the change and the number of coins or bils needed for the change.
*/

#include <stdio.h>
int main()
{
	int cost,money,mnr;
	printf("Enter the cost of the product: ");
	scanf("%d",&cost);
	printf("Enter the amount of money paid: ");
	scanf("%d",&money);
	mnr=money-cost;
	int notes[]={2000,500,200,100,50,20,10,5,2,1},i;
	printf("\n\nMoney required to return %d\n\n",mnr);
	for(i=0;i<10;i++)
	{
		if(mnr/notes[i]!=0 && i<7)
		printf("Number of %d Rs. notes required are: %d\n",notes[i],mnr/notes[i]);
		else if(mnr/notes[i]!=0 && i>6)
		printf("Number of %d Rs. coins required are: %d\n",notes[i],mnr/notes[i]);
		mnr=mnr%notes[i];
	}
	return 0;
}