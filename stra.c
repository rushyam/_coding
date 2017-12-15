//https://www.codechef.com/problems/SMRSTR
#include <stdio.h>
int main()
{
	int f,t;
	scanf("%d",&t);
	for(f=0;f<t;f++)
	{
		long long int n,q,i,j;
		scanf("%lld%lld",&n,&q);
		long long int d[100000];
		long long int x[100000];
		for (i = 0; i < n; i++)
			scanf("%lld",&d[i]);
		for (i = 0; i < q; i++)
			scanf("%lld",&x[i]);
		for(i=0;i<q;i++)
		{	
			long long int temp=x[i];
			for(j=0;j<n;j++)
				temp = (temp/d[j]); 
			printf("%lld ", temp);
		}
		printf("\n");
	}
	return 0;
}