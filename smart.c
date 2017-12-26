#include <stdio.h>
int main()
{
	int f,t;
	scanf("%d",&t);
	for(f=0;f<t;f++)
	{
		int n,Q,i,j;
		int d[100000],q[100000];
		scanf("%d%d",&n,&Q);
		for(i=0;i<n;i++)
			scanf("%d",&d[i]);
		for(i=0;i<Q;i++)
			scanf("%d",&q[i]);
		for(i=0;i<Q;i++)
		{
			int temp=q[i];
			for(j=0;j<n;j++)
			{
				temp = temp/d[j];
			}
			printf("%d ",temp);
		}
		printf("\n");
	}
	return 0;
}