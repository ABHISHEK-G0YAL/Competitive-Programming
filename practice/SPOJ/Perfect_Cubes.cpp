// https://www.spoj.com/problems/CUBES/

#include <iostream>
#define n 100
#define cube(x) (x*x*x)
using namespace std;
 
int main() {
	for(int a=6;a<=n;a++)
		for(int i=2;i<a;i++)
			for(int j=i;j<a;j++)
				for(int k=j;k<a;k++)
					if(cube(a)==cube(i)+cube(j)+cube(k))
						cout<<"Cube = "<<a<<", Triple = ("<<i<<","<<j<<","<<k<<")"<<endl;
							return 0;
}