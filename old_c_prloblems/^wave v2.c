/*
Enter the width of the Wave
5
Enter the length of the Wave
8
       /\              /\              /\              /\              /\
      /  \            /  \            /  \            /  \            /  \
     /    \          /    \          /    \          /    \          /    \
    /      \        /      \        /      \        /      \        /      \
   /        \      /        \      /        \      /        \      /        \
  /          \    /          \    /          \    /          \    /          \
 /            \  /            \  /            \  /            \  /            \
/              \/              \/              \/              \/              \

Enter the width of the Wave
8
Enter the length of the Wave
2
 /\  /\  /\  /\  /\  /\  /\  /\
/  \/  \/  \/  \/  \/  \/  \/  \

*/

#include<stdio.h>
void main()
{
	int i,n1,n2,m1,m2=1;
	printf("Enter the width of the Wave\n");
	scanf("%i",&n1);
	printf("Enter the length of the Wave\n");
	scanf("%i",&n2);
	for(m1=1;m1<=n1;m1++)
	{
		while(m2<=n2)
		{
			for(i=1;i<=(n2-m2);i++)
				printf(" ");
			printf("/");
			for(i=1;i<m2;i++)
				printf("  ");
			printf("\\");
			for(i=1;i<=(n2-m2);i++)
				printf(" ");
			if(m1<n1)
				break;
			else
			{
				m1=1;
				printf("\n");
				++m2;
			}
		}
	}
}