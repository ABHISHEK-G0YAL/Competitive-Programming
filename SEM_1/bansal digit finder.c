#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i;int count=0;int l;int g;int f,x,m,y,A;
	int pos=1986;
    for(i=1;i<=999;i++)
    {
        if(i<=9)
        {
            count++;
        }
		else if(i>9&&i<100)
    	{
			for(l=1;l<=2;l++)
    		{
        		if(l==1)
        		{
            		count++;
            		if(count==pos)
                	{
                		g=i/10;
                    	printf("%d\n",g);
                    	printf("%d",i);
                    	break;
	                }
				}
				if(l==2)
            	{
                	count++;
                	if(count==pos)
                	{
                	    f=i%10;
                	    printf("%d\n",f);
                	    printf("%d",i);
                	    break;
                	}
            	}
        	}
    	}
    	else if(i>99)
    	{
			for(l=1;l<=3;l++)
        	{
        		if(l==1)
            	{
            		count++;
                	if(count==pos)
                	{
                    	x=i/100;
                    	printf("%d\n",x);
                    	printf("%d",i);
                    	break;
                	}
            	}
            	if(l==2)
            	{
                	count++;
                	if(count==pos)
                	{
                    	m=i/10;
                    	y=m%10;
                    	printf("%d\n",y);
                    	printf("%d",i);
                    	break;
					}
            	}
				if(l==3)
            	{
                	count++;
                	if(count==pos)
                	{
                    	A=i%10;
                    	printf("%d\n",A);
                    	printf("%d",i);
                    	break;
                	}
            	}
			}
		}
		if(count==pos)
    	{
        	break;
    	}
	}
	return 0;
}
