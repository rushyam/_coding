#include <stdio.h>
#include <stdlib.h>
int main()
{
	int f,t;
	scanf("%d",&t);
	for(f=0;f<t;f++)
	{
		int n,k,i,j;
		scanf("%d%d",&n,&k);
		int *a = (int *)malloc(n*sizeof(int));
		int *b = (int *)malloc(n*k*sizeof(int));
		for (int i = 0; i < n; i++)
			scanf("%d",&a[i]);
		for (int i = 0; i < n*k; i++)
			b[i] = a[i%n];
		printf("%d\n", find(b,0,n*k-1));
	}
	return 0;
}