//https://www.codechef.com/problems/KFIB
#include <stdio.h>
#include <stdlib.h>
int sum(int a[],int k)
{
	int i,count = 0;
	for(i=0;i<k;i++)
		count += a[i];
	return count;
}
int rotate(int a[],int k)
{
	int i;
	for(i=0;i<k-1;i++)
		a[i]=a[i+1];
}
int main()
{
	int n,k,i;
	scanf("%d%d",&n,&k);
	int *a=(int *)malloc(k*sizeof(int));
	for(i=0;i<k;i++)
		a[i]=1;
	int c=k,s;
	while(c!=n)
	{
		s=sum(a,k);
		rotate(a,k);
		a[k-1]=s;
		c++;
	}
	printf("%d\n",a[k-1]%(1000000007));
	return 0;
}