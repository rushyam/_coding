#include <stdio.h>
#include <stdlib.h>
int max(long a[],int n,long b[],int i)
{
	int j;
	long m=-1;
	if(i==0)
	{	
		for(j=0;j<n;j++)
			if(m<a[j])
				m=a[j];
		return m;
	}
	for(j=0;j<n;j++)
		if( a[j] < b[i-1])
			if( m < a[j])
				m= a[j];
	return m;
}
int main()
{
	int f,t;
	scanf("%d",&t);
	for(f=0;f<t;f++)
	{ 
		int n,i,j,flage=0;
		long c=0;
		
		scanf("%d",&n);
		
		long **a = (long **)malloc(n*sizeof(long *));
		for(i = 0; i<n ; i++)
			a[i] = (long *)malloc(n*sizeof(long));
		
		long *b = (long *)malloc(n*sizeof(long));
		
		for (i=n-1;i>=0;i--)	
			for(j=0;j<n;j++)
				scanf("%ld",&a[i][j]);
		
		for(i=0;i<n;i++)
		{
			b[i] = max(a[i],n,b,i);
			if(b[i] == -1)
			{
				printf("-1\n");
				flage=1;
				break;
			}
			c += b[i];
		}
		if(flage == 0)
			printf("%ld\n", c);
	}
	return 0;
}