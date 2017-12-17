//https://www.codechef.com/problems/RNDPAIR
#include <stdio.h>
int main()
{
	int f,t;
	scanf("%d",&t);
	for(f=0;f<t;f++)
	{
		int max = 0, i, j;
		float count = 0.0, c = 0.0;
		int n,a[100];
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(j=1;j<n;j++)
		{
			for(i=0;i<j;i++)
				{
					if((a[i]+a[j])>max)
					{
						max = a[i] + a[j];
						count = 0.0;
					}
					if((a[i]+a[j])==max)
						count += 1.0;
					c += 1.0;
				}
		}
		printf("%f\n",(count/c) );
	}
	return 0;
}