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
		long m = -1000001, max_so_far = 0, max_endding_here = 0;
		long s = sum;
		if(k>=2)
		{	
			for(i=0;i<n;i++)
			{
				long x = sum*(k-2) + 2 * s;
				if( x > m)
					m = x;
				s = s-a[i];
			}
		} 
		long f = a[0];
		for(i=0;i<n;i++)
		{
			if(max_endding_here + a[i] > 0)		
				max_endding_here += a[i];
			if(max_endding_here > max_so_far)
				max_so_far = max_endding_here;
			if(f < a[i])
				f = a[i];
		}	
		if(max_so_far > m)
			m = max_so_far;
		if(f < 0)
			m = f;
		printf("%ld\n",m);
	}
	return 0;
}
