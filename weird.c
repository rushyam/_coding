#include <stdio.h>
#include <stdlib.h>

void swap(int **a,int n,int p)
{
	int temp;
	temp=a[p][p+1];
	a[p][p+1] = a[p+1][p];
	a[p+1][p]=temp;
}
int cost(int **a,int n)
{
	int c=0,cost=0,i,j;
	for(i=0;i<n;i++)
	{
		c=0;
		for(j=0;j<n;j++)
			c += a[i][j];
		cost += c*c;
	}
	return cost;
}
void print(int **a,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d",a[i][j]);
		printf("\n");
	}
}
int change(int **a,int n,int k,int p,int l);

int permute(int **a,int n,int k,int p);

int main()
{
	int f,t;
	scanf("%d",&t);

	for(f=0;f<t;f++)
	{
		int k,n,i,j;
		scanf("%d%d",&n,&k);
		
		int **a=(int **)malloc(n*sizeof(int *));
		for(i=0;i<n;i++)
			a[i]=(int *)calloc(n,sizeof(int));
		
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(j>i)
					a[i][j]=1;

		swap(a,n,2);
		print(a,n);

	    //permute(a,n,k,0);

	}
return 0;
}
int change(int **a,int n,int k,int p,int l)
{
	int i;
	if(l == n)
		permute(a,n,k,p);
	else
		{
			for(i=l;i<n;i++)
			{
				swap(a,n,i);
				change(a,n,k,p,i);
				swap(a,n,i);
			}
		}
 return 0;
}

int permute(int **a,int n,int k,int p)
{
	int i,j;
	if(n-p == 2)
	{
		if(cost(a,n) == k)
			{
				print(a,n);
				return 0;
			}
		swap(a,n,p);
		if(cost(a,n) == k)
			print(a,n);
		swap(a,n,p);
		return 0;
	}
	else
		change(a,n,k,p,p);

}