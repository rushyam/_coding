#include <stdio.h>
#include <stdlib.h>
int main()
{
	long n,i,j,q;
	scanf("%ld",&n);
	long *h = (long *)malloc(n*sizeof(long));
	for(i = 0; i < n ; i++)
		scanf("%ld",&h[i]);
	scanf("%ld",&q);
	long *x = (long *)malloc(q*sizeof(long));
	long *y = (long *)malloc(q*sizeof(long));
	for(i=0;i<q;i++)
		scanf("%ld%ld",&x[i],&y[i]);
	long count = n;
	for(j=0;j<q;j++)
	{
		for(i=0; i<n ; i++)
		{
			if(h[i] <= 0)
				continue;	
			long a = x[j];
			if((i & a) == i)
				h[i] = h[i] - y[j];
			if(h[i]<=0)
				count--;
		}
		printf("%ld\n",count);
	}
	return 0;
}