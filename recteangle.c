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
	for(k=i+1;k<j;k++)
		if(min_y>p[k].y)
			min_y = p[k].y;
	return min_y;
}
int area(point *p,int *n,int i,int j,int *max)
{
	int a;
	if(i+1 == j)
	{
		a = 500*(p[j].x-p[i].x);
		if(a>*max)
			*max= a;
		if(j == *n )
			return 0;
	}
	int y=min(p,n,i,j);
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
void merge(point *p,int l,int m,int r)
{
	int i,j,k;
	int n1 =m-l+1;
	int n2 =r-m;
	point *a=(point *)malloc((n1)*sizeof(point));
	point *b=(point *)malloc((n2)*sizeof(point));
	for(i=0;i<n1;i++)
	{
		a[i].x=p[l+i].x;
		a[i].y=p[l+i].y;
	}
	for(i=0;i< n2;i++)
	{
		b[i].x=p[m+1+i].x;
		b[i].y=p[m+1+i].y;
	}
	i=0;
	j=0;
	k=l;
	while (i < n1 && j < n2)
    {
        if (a[i].x <= b[j].x)
        {
            p[k].x = a[i].x;
            p[k].y = a[i].y;
            i++;
        }
        else
        {
            p[k].x = b[j].x;
            p[k].y = b[j].y;
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        p[k].x = a[i].x;
        p[k].y = a[i].y;
        i++;
        k++;
    }
 while (j < n2)
    {
        p[k].x = b[j].x;
        p[k].y = b[j].y;
        j++;
        k++;
    }


}
void merge_sort(point *p,int l,int r)
{
	if(l<r)
	{
		int m = (l+r)/2;
		merge_sort(p,l,m);
		merge_sort(p,m+1,r);
		merge(p,l,m,r);
	}
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
	merge_sort(p,0,n);
	// for(i=1;i<=n;i++)
	// {
	// 	for(j=1;j<=n;j++)
	// 	{
	// 		if(p[i].x < p[j].x)
	// 		{
	// 			short temp1;
	// 			int temp;
	// 			temp = p[i].x;
	// 			temp1 = p[i].y;
	// 			p[i].y = p[j].y;
	// 			p[i].x = p[j].x;
	// 			p[j].y = temp1;
	// 			p[j].x = temp;
	// 		}
	// 	}
	// }
	int max=-1;
	for(i=0;i<=n;i++)
	{
		j=i+1;
		if(i==n)
			j=i;
		area(p,&n,i,j,&max);
	}
	printf("%d\n",max);
	return 0;
}