#include<stdio.h>
#include<string.h>
int main()
{
	char str[100],str2[100];
	int i,j,k,len;
	printf("enter the string: ");
	gets(str);
	len=strlen(str);
	i=0;
	j=0;
	while(str[i]!='\0')
	{
		if(str[i]=='i'||str[i]=='a'||str[i]=='e'||str[i]=='o'||str[i]=='u'||str[i]==' ')
		{
			if(str[i]!=' ')
			{
				str2[j]=str[i];
				j=j+1;
			}
			for(k=i;k<len;k++)
				str[k]=str[k+1];
			len=len-1;
		}
		else
		i++;		
	}
	str[i]=' ';
	str2[j]='\0';
	strcat(str,str2);
	printf("%s",str);
}
