#include <stdio.h>
#include<math.h>
int cost(int a[][230],int x,int y);
int main()
{
	int c,f,a[230][230],i,j;
	for(i=0;i<230;i++)
		for(j=0;j<230;j++)
			a[i][j] = -1;
	scanf("%d%d",&c,&f);
	for(i=0;i<f;i++)
	{
		int x,y,p;
		scanf("%d%d%d",&x,&y,&p);
		a[x][y] = p;
	}	
	for(i=0;i<230;i++)
		for(j=0;j<230;j++)
			if(a[i][j]!=-1)
				a[j][i]=a[i][j];
	int max = 0,p;
	for(i=0;i<c;i++)
	{
		for(j=0;j<c;j++)
		{
			if(i == j)
				continue;
			p = cost(a,i,j);
			if(max < p);
				max =p;
		}
	}
	printf("%d\n", max);
	return 0;
}
int cost(int a[][230],int x,int y)
{
	int i,j,c;
	if(a[x][y] != -1)
		 c= a[x][y];

	int min = 3000000;
	for(i=0;i<230;i++)
	{	
		if(a[x][i]!=-1)
			{
				int temp = cost(a,i,y);
				if(min > temp)
					min =temp;
			}		
	}
	if(min>c)
		min =c;
	return min;
}



