#include <stdio.h>
#include <stdlib.h>
int permute(char a[], int a_i, char b[], int b_i, char c[], int c_i, int n, int m)
{
	if(a_i == n)
	{

	}
	if(b_i == m)
	{

	}
}

int main()
{
	int f,t;
	scanf("%d",&t);
	for(f=0;f<t;f++)
	{
		int n,m,i;
		scanf("%d%d",&n,&m);
		char *a = (char *)malloc(n+1*1);
		char *b = (char *)malloc(m+1*1);
		scanf("%s",&a);
		scanf("%s",&b);
		char *c = (char *)malloc(((n+m)+1)*1);
		c[n+m] = '\0'; 
		permute(a,0,b,0,c,0,n,m);
	}
	return 0;
}