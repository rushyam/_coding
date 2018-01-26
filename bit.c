#include <stdio.h>
int binary(int n,int a[])
{
	int i;
	long temp = n;
	for(i=0;;i++)
	{
		a[i] = temp%2;
		temp = temp/2;
		if(temp == 0)		
			break;	
	}	
	return i;
}
int main()
{
	long f,t;
	scanf("%ld",&t);
	for(f=0;f<t;f++)
	{
		long n,i,j;
		scanf("%ld",&n);
		int a[40];
		int b=binary(n, a);
		long count = 0;
		for(i=b;i>0;i--)
		{
			for(j=i-1; j >=0; j--)
				count += a[i]*2 + a[j];
		}
		printf("%ld\n",count );
	}
	return 0;
}