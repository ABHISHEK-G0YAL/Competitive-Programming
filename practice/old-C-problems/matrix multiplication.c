#include<stdio.h>
void main()
{
	printf("Program to multiply 2 matrix.\n\n");
	int io,jo,mo,no,i,j,m,n;
	printf("Enter the order of first matrix.\n");
	scanf("%d %d",&io,&jo);
	printf("Enter the order of second matrix.\n");
	scanf("%d %d",&mo,&no);
	if(jo==mo)
	{
		float a[io][jo];
		float b[mo][no];
		printf("\nEnter the first matrix A of order %dx%d:\n",io,jo);
		for(i=0;i<io;i++)
		{
			for(j=0;j<jo;j++)
			{
				printf("Enter A(%d,%d)-\n",(i+1),(j+1));
				scanf("%f",&a[i][j]);
			}
		}
		printf("\nEnter the second matrix B of order %dx%d:\n",mo,no);
		for(m=0;m<mo;m++)
		{
			for(n=0;n<no;n++)
			{
				printf("Enter B(%d,%d)-\n",(m+1),(n+1));
				scanf("%f",&b[m][n]);
			}
		}
		printf("\n\nMatrices you entered are:-\n\n");
		for(i=0;i<io;i++)
		{
			for(j=0;j<jo;j++)
			{
				printf("\t%g",a[i][j]);
			}
			printf("\n\n");
		}
		printf("\n\n");
		for(m=0;m<mo;m++)
		{
			for(n=0;n<no;n++)
			{
				printf("\t%g",b[m][n]);
			}
			printf("\n\n");
		}
		float c[io][no];
		for(i=0;i<io;i++)
		{
			for(n=0;n<no;n++)
			{
				c[i][n]=0;
			}
		}
		for(i=0;i<io;i++)
		{
			for(n=0;n<no;n++)
			{
				for(j=0;j<jo;j++)
				{
					c[i][n]=(a[i][j]*b[j][n])+c[i][n];
				}
			}
		}
		printf("\n\nThe product of these matrices is:-\n\n");
		for(i=0;i<io;i++)
		{
			for(n=0;n<no;n++)
			{
				printf("\t%g\t",c[i][n]);
			}
			printf("\n\n");
		}	
	}
	else
	{
		printf("\n\nThe matrices of order %dx%d and %dx%d can't be multiplied.\nP.S. Go and study some mathematics.\n",io,jo,mo,no);
	}
}