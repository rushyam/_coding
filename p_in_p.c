#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int count;
typedef struct Point
{
	int x,y;
}point;
int Ar(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2)));
}
int find(point p[],int n,int f,int o,int t)
{
	point temp[3];

	temp[0].x = p[f].x;
	temp[0].y = p[f].y;
	temp[1].x = p[o].x;
	temp[1].y = p[o].y;
	temp[2].x = p[t].x;
	temp[2].y = p[t].y;

	int i,j;
	int max_x=p[f].x,min_x=p[f].x,max_y=p[f].y,min_y=p[f].y;

	// printf("(%d %d) (%d %d) (%d %d)\n",temp[0].x, temp[0].y, temp[1].x , temp[1].y, temp[2].x, temp[2].y );

	for(i=0;i<3;i++)
	{
		if(max_x<temp[i].x)
			max_x = temp[i].x;
		if(min_x>temp[i].x)
			min_x = temp[i].x;
		if(max_y<temp[i].y)
			max_y = temp[i].y;
		if(min_y>temp[i].y)
			min_y = temp[i].y;
	}
	for(i=min_x;i<=max_x;i++)
		{
			if(count == n/10)
			   	break;
			for(j=min_y;j<=max_y;j++)
			{
			   if(count == n/10)
			   		break;
			   int A = Ar(temp[0].x, temp[0].y, temp[1].x , temp[1].y, temp[2].x, temp[2].y);
			   int A1 = Ar(temp[0].x, temp[0].y, temp[1].x, temp[1].y, i, j);
			   int A2 = Ar(temp[1].x, temp[1].y, temp[2].x, temp[2].y, i ,j);
			   int A3 = Ar(temp[0].x, temp[0].y, temp[2].x, temp[2].y, i, j);
			   
			   if(A1 == 0 || A2 == 0)
			   		continue;
			   if(A3 == 0 && t == n-1)
			   	   continue;
			   if(A == A1 + A2 + A3)
			   {
			   		printf("%d %d\n",i,j);
			   		count ++;
	 		   }
			}
		}
		// printf("===============================================\n");
}
int viraj(point p[],int n,int f,int o,int t)
{
	if(t<=n-1 && count < n/10)
	{
		find(p,n,0,o,t);
		o = t;
		t = t+1;
		viraj(p,n,0,o,t);
	}
}
int main()
{
	int f,t;
	scanf("%d",&t);
	for(f=0;f<t;f++)
	{
		int n,i;
		count = 0;
		
		scanf("%d",&n);
		
		point *p = (point *)malloc(n*sizeof(point));
		
		for(i=0;i<n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		
		viraj(p,n,0,1,2);
		
		if(count < n/10)
		{
			int a = -1;
		 	printf("%d\n",a);
		}
	}
	return 0;
}