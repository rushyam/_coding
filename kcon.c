#include <stdio.h>
#include <stdlib.h>
int main()
{
	long f,t;
	scanf("%ld",&t);
	for(f=0;f<t;f++)
	{
		long n,k,i,j;
		scanf("%ld%ld",&n,&k);
		long *a = (long *)malloc(n*sizeof(long));
		long sum = 0;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a[i]);
			sum += a[i];
		}
		long s = sum;
		long  max_so_far = -1000001, max_ending_here = 0,m = -1000001;
		if(k>2 && sum >0)
		{	
			long max;
			long s1= -1000001, s2=-1000001,c=sum,b=sum;
			for(i=0;i<n;i++)
			{		
				if(s1 < b)
					s1 =b;
				if(s2 < c)
					s2 = c;
				max = sum * (k-2) + s1 + s2 ;
				if(m < max)
					m = max;
				b -= a[i];
				c -= a[n-i-1];
			}
		}
		int x = 2;
		if(k == 1)
			x = 1;
		for(i=0;i<n*x;i++)
		{
			max_ending_here = max_ending_here + a[i%n];
        	if (max_so_far < max_ending_here)
            	max_so_far = max_ending_here;
        	if (max_ending_here < 0)
            	max_ending_here = 0;
		}
        if(m < max_so_far)
        	m = max_so_far;
		printf("%ld\n",m);
	}
	return 0;
}
