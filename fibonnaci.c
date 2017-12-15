//https://www.codechef.com/problems/KFIB
#include <stdio.h>
int T(int n,int k)
{
	if(n<=k)
		return 1;
	int i,count=0;
	for(i=1;i<=k;i++)
		count += T(n-i,k);
	return count;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	printf("%d",(T(n,k)%1000000007));

	return 0;
}