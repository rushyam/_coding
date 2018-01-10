#include <stdio.h>
#include <stdlib.h>
int max1(int a,int b)
{
	return a>b?a:b;
}
int max(int a,int b,int c)
{
	return max1(max1(a,b),c);
}
int max_s(int a[],int l,int m,int r,int n)
{
	int sum=0,i;
	int max_l = -1000001;
	for(i=m;i>=0;i--)
	{
		sum += a[i%n];
		if(sum>max_l)
			max_l = sum;
	}
	sum = 0;
	int max_r = -1000001;
	for(i=m+1;i<=r;i++)
	{
		sum += a[i%n];
		if(sum > max_r)
			max_r = sum;
	}
	return (max_r+max_l);
}
int max_sum(int a[],int l,int r,int n)
{
	if(l==r)
		return a[l%n];
	int m = (l+r)/2;
	return max(max_sum(a,l,m,n),max_sum(a,m+1,r,n),max_s(a,l,m,r,n));
}
int main()
{
	int f,t;
	scanf("%d",&t);
	for(f=0;f<t;f++)
	{
		int n,k,i,j;
		scanf("%d%d",&n,&k);
		int *a = (int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);	
		printf("%d\n",max_sum(a, 0, n*k-1, n));
	}
	return 0;
}
