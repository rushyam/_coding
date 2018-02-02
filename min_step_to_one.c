#include <stdio.h>
int minimum(int a,int b,int c)
{
	int d = a>b?b:a ;
	return d>c?c:d ;
}
int min(int n)
{
	if(n == 1)
		return 1;
	else
	{
		int two,three;
		if(n%2 == 0)
			two = min(n/2);
		if(n%3 == 0)
			three = min(n/3);

		return 1 + minimum(min(n-1),two,three);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",min(n));	
	return 0;
}
