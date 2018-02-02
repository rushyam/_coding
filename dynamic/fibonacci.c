#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	int temp0 = 1,temp1 = 1;
	int *a = (int *)malloc(n*(sizeof(int))); 
	a[0] = temp0;
	a[1] = temp1; 
	for(i=0;i<n;i++)
	{
		int temp = temp1;
		temp0 = temp0 + temp1;
		temp1 = temp0;
		temp0 = temp;
		printf("%d\t%d\n",temp0,temp1);
	}
	return 0;
}