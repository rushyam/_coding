#include <stdio.h>
#include <math.h>
#include<iostream>

using namespace std;
long mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}

void answer(double y)
{
	long int p=0,q=0;
	for(long int i=1;i<1000;i++)
	{
		if((y*i)-(int)(y*i) <0.001)
		{
			p=(long int)(y*i);
			q=(long)i;
			break;
		}
	}
	// cout<<p<<' '<<q<<endl;
	// q=q%1000000007;
	long int r;
	for(long int i=1;i<1000;i++)
	{
		if((q*i)%1000000007 == 1)
		{
			r=i;
			break;
		}
	}
	// cout<<"r "<<r<<endl;
	if(p*r==0)
	{
		cout<<0<<endl;
		return;
	}
	if(p*r<0)
	{
		cout<<(1000000007-(-1*p*r)%1000000007)<<endl;
	}
	else	cout<<(p*r)%1000000007<<endl;
}
// int main()
// {
// 	while(1)
// 	{
// 		double d;
// 		cin>>d;
// 		answer(d);
// 	}
// 	return 0;
// }
int main()
{
	int f,t;
	scanf("%d",&t);
	for(f=0;f<t;f++)
	{
		double l,d,t;
		
		scanf("%lf%lf%lf",&l,&d,&t);
		
		double angle = acos((d/l));
		
		angle = (angle) * t;
				
		double y = l * cos(angle); 
		

		// answer(y);
		double f_y,i_y;
		

		// if(y >= 0)
		// 	{
		// 		printf("%ld\n",((long)y)%1000000007 );
		// 		continue;
		// 	}
		f_y = modf(y,&i_y);
		
		if(f_y < -0.999 && i_y < 0)
		{
			f_y = 0.0;
			i_y = i_y - 1.0;
		}

		// if(f_y == 0.0)
		// {
		// 	printf("%ld\n",mod(i_y,1000000007) );
		// 	continue;
		// }		
		answer(i_y+f_y);
	}
	return 0;
}