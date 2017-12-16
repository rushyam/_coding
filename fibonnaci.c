//https://www.codechef.com/problems/KFIB
#include <stdio.h>
#include <stdlib.h>
int sum(int a[],int k,int s)
{
	int i,count = 0;
	for(i=s;i<k;i++)
		count += a[i];
	return count;
}
// int rotate(int a[],int k)
// {
// 	int i;
// 	for(i=0;i<k-1;i++)
// 		a[i]=a[i+1];
// }
int main()
{
	int n,k,i;
	scanf("%d%d",&n,&k);
	int *a=(int *)malloc(n*sizeof(int));
	for(i=0;i<k;i++)
		a[i]=1;
	int c=k,s;
	for(i=k;i<n;i++)
	{
		s=sum(a,i,i-k);
		a[i]=s;
	}
	printf("%d\n",a[n-1]%(1000000007));
	return 0;
}