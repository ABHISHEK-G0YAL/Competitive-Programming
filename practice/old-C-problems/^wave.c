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
	int m,i,s1,s2,n1,n2,z;
	z=1;
	printf("Enter the width of the Wave\n");
	scanf("%i",&n1);
	printf("Enter the length of the Wave\n");
	scanf("%i",&n2);
	for(m=1;m<=n1;m++)
	{
		while(z<=n2)
		{
			for(s1=1;s1<=(n2-z);s1++)
			{
				printf(" ");
			}
			printf("/");
			for(s2=1;s2<z;s2++)
			{
				printf("  ");
			}
			printf("\\");
			for(s1=1;s1<=(n2-z);s1++)
			{
				printf(" ");
			}
			if(m<n1)
			{
				goto label;
			}
			else
			{
				m=1;
				printf("\n");
				++z;
			}
		}
		label:;
	}
}