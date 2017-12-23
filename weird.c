//https://www.codechef.com/problems/WEICOM
#include <stdio.h>
#include <stdlib.h>
int flage = 0;
int check(short a[],int *n,int *p)
{
	if(flage == 1)
		return 0;
	int i,j=0,k=1,c,count=2;
	short **b=(short**)calloc(*n,sizeof(short*));
	for(i=0;i<*n;i++)
		b[i]=(short*)calloc(*n,sizeof(short));
	for(i=0;i<(*n*(*n-1))/2;i++)
	{
		b[j][k] = a[i];
		k++;
		if(i == *n-count)
		{
			k=count;
			count++;
			j++;
		}
	}
	int t=*n;
	for (i = 0; i < t; i++)
	{
		for (j = 0; j < t; j++)
		{
			if(j>i)
			{
				if(b[i][j] == 0)
					b[j][i] =1;
				if(b[i][j] == 1)
					b[j][i] =0;
			}
		}
	}
	count=0;
	for (i = 0; i < t; i++)
	{
		c=0;
		for (j = 0; j < t; j++)
		{
			c += b[i][j];
		}
		count += c*c;
	}
	
	if(*p == count)
	{
		for (i = 0; i < t; i++)
		{
			for (j = 0; j < t; j++)
			{	
				printf("%hd",b[i][j] );
			}
			printf("\n");
		}
		flage = 1;
	}
	 return 0;
}
int c=0;
int permute(short a[],int *n,int *t,int *p)
{
	if(c == (*t)-1)
	{
		a[c] = 0;
		check(a,n,p);
		a[c] = 1;
		check(a,n,p);
	}
	else
	{
		a[c] = 0;
		c++;
		permute(a,n,t,p);
		c--;
		a[c] = 1;
		c++;
		permute(a,n,t,p);
		c--;
	}
	return 0;
}
int main()
{
	int f,t;
	scanf("%d",&t);
	for(f=0 ; f<t ; f++)
	{
		flage = 0;
		int x=-1;
		int i,n,k;
		scanf("%d%d",&n,&k);
		int t = n*(n-1)/2;
		short *a = (short*)calloc(t,sizeof(short));
		permute(a,&n,&t,&k);
		if(flage == 0)
			printf("%d\n", x);
	} 
	return 0;
}