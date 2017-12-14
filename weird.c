#include <stdio.h>
#include <stdlib.h>
int n;
int cost(int a[][n])
{
	int i,j,count=0;
	
	return count;
}
void print(int a[][n])
{
	int i,j;
	
}
int main()
{
	int f,t;
	scanf("%d",&t);
	for(f=0;f<t;f++)
	{
		int k,i,j;
		scanf("%d%d",&n,&k);
		int **a=(int **)malloc(n*sizeof(int *));
		for(i=0;i<n;i++)
			a[i]=(int *)calloc(n,sizeof(int));
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(j>i)
					a[i][j]=1;
		int c = 0, count = 0;
		int *b=(int *)calloc(n,sizeof(int));
		for(i=0;i<n;i++)
		{
			c = 0;
			for(j=0;j<n;j++)
				c += a[i][j];
			count += c*c;
		}

		if(count == k)
			{
				for(i=0;i<n;i++)
					{
						for(j=0;j<n;j++)
							printf("%d",a[i][j]);
						printf("\n");
					}
			}
	 	else
	 		printf("%d",-1);
	 }
return 0;
}