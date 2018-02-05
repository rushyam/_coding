#include <stdio.h>
int main()
{
	int f,t;
	scanf("%d",&t);
	for(f=0;f<t;f++)
	{
		int n,i;
		scanf("%d",&n);
		int *l =(int *)malloc(n*sizeof(int));
		int *r =(int *)malloc(n*sizeof(int));;
		for(i=0;i<n;i++)
			scanf("%d %d",&l[i],&r[i]);
		int q;
		scanf("%d",&q);
		int *m =(int *)malloc(q*sizeof(int));
		int **x = (int **)malloc(q*sizeof(int));
		for(i=0;i<q;i++)
		{
			scanf("%d",&m[i]);
			x[i] = (int *)malloc(m[i]*sizeof(int));
		}
		


		
	}
	return 0;	
}