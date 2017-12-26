#include <stdio.h>
#include <stdlib.h>
typedef struct point
{
	int x;
	short y;
}point;
int min(point *p,int *n,int i,int j)
{
	int min_y=500,k;
	if(j== *n)
	{
		for(k=i+1;k<j;k++)
			if(min_y>p[k].y)
				min_y = p[k].y;
		return min_y;
	}
	for(k=i+1;k<j;k++)
		if(min_y>p[k].y)
			min_y = p[k].y;
	return min_y;
}
int area(point *p,int *n,int i,int j,int *max)
{
	int a;
	int y=min(p,n,i,j);
	if(i+1 == j)
	{
		a = 500*(p[j].x-p[i].x);
		if(a>*max)
			*max= a;
		if(j == *n )
			return 0;
	}
	if(j == *n )
	{	
		a=y*(100000-p[i].x);
		if(a>*max)
			*max = a;
		return 0;
	}
	else
	{
		a = y*(p[j].x-p[i].x);
		if(a>*max)
			*max= a;
	}
	j++;
	area(p,n,i,j,max);
return 0;
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	point *p = (point*)malloc((n+1)*sizeof(point));
	for(i=1;i<=n;i++)
		scanf("%d%hd",&p[i].x,&p[i].y);
	p[0].x = 0;
	p[0].y = 0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)
				continue;
			if(p[i].x < p[j].x)
			{
				short temp1;
				int temp;
				temp = p[i].x;
				temp1 = p[i].y;
				p[i].y = p[j].y;
				p[i].x = p[j].x;
				p[j].y = temp1;
				p[j].x = temp;
			}
		}
	}
	int max=-1;
	for(i=0;i<=n;i++)
		area(p,&n,i,i,&max);
	printf("%d\n",max);
	return 0;
}