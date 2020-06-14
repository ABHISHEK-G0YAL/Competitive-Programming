#include<stdio.h>
#include<string.h>
int main()
{
  int T;
  scanf("%d",&T);
  long long int shield,S,C;
  char program[30];
  while(T)
  {
  	  shield=0;S=0;C=1;
  	  memset(program,0,strlen(program));
 	  scanf("%lld",&shield);
      scanf("%s",program);
      int i;
      for(i=0;i<strlen(program);i++)
      {
      	if(program[i]=='S')
      		S+=C;
      	else
			C=(C*2);  	
	  }
	  if(S <= shield)
	  	{printf("0");}
      printf("%lld\n",S);
      T--;
  }
  return 0;
}
