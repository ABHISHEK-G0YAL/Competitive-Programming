#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    unsigned int cases=1,games=2,I=1,T=5,Q=1;
    scanf("%u",&cases);
    if (!(cases>=1 && cases<=10))
    {
        printf("ENTER NUMBER OF TEST CASES BETWEEN 1-10");
        return 0;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    for(int i=0;i<cases;i++)
    {
    	scanf("%u",&games);
        if(!(games>=1 && games<=20000))
        {
            printf("GIVE GAMES BETWEEN 1-20000");
            continue;
        }  
    	
        while(games>0)
         {
         scanf("%u %u %u",&I,&T,&Q);
        if(!((I>=1 && I<=2) && (T>=1 && T<=109) && (Q>=1 && Q<=2)))
        {
            printf("ENTER RIGHT INPUTS");
            continue;
        }
            if((T%2==0))
                printf("%u \n",T/2);
            else if((T%2==1)&&(I==Q))
                printf("%u \n",T/2);
            else
                printf("%u \n",T-(T/2));
        games--;
         }
    }
    return 0;
}

