#include <iostream>
#include<string>
using namespace std;

int main()
{
int num,p;
string rm;
cout<<"enter the number bw 1-4000\n";
cin>>num;
if(num>=4000||num<=0)
cout<<"invalid number";
else
     {
       if(num>=1000)
          {
            p=num/1000;
            for(int i=0;i<p;i++)
                {
                  rm+='M';
                }
            num=num%1000;
          }

      if(num>=100)
          {
            p=num/100;
            if(p==9)
            rm+="CM";
            else if(p>=5)
               {    rm+='D';
                    for(int i=0;i<p-5;i++)
                    rm+='C';
               }
           else if(p>=1&&p<4)
               {  
                   for(int i=0;i<p;i++)
                    rm+='C';
               }
           else
           rm+="CD";
           num=num%100;
         }
      if(num>=10)
          {
            p=num/10;
            if(p==9)
            rm+="XC";
            else if(p>=5)
               {    rm+='L';
                    for(int i=0;i<p-5;i++)
                    rm+='X';
               }
           else if(p>=1&&p<4)
               {  
                   for(int i=0;i<p;i++)
                    rm+='X';
               }
           else
           rm+="XL";
           num=num%10;
         }
     if(num>=1)
          {
            p=num;
            if(p==9)
            rm+="IX";
            else if(p>=5)
               {    rm+='V';
                    for(int i=0;i<p-5;i++)
                    rm+='I';
               }
           else if(p>=1&&p<4)
               {  
                   for(int i=0;i<p;i++)
                    rm+='I';
               }
           else
           rm+="IV";
        
         }

cout<<"the roman numeral is\t"<<rm;
        

     }
return 0;
}
