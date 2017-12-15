// https://www.codechef.com/problems/GIT01

#include <stdio.h>
int cost(int b[][100],int c[][100],int d[][100],int n,int m)
{
	int i,j,cost1=0,cost2=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			{
				if(b[i][j]-c[i][j] == 2)
					cost1 += 3;
				if(b[i][j]-c[i][j] == -2)
					cost1 += 5;
				if(b[i][j]-d[i][j] == 2)
					cost2 += 3;
				if(b[i][j]-d[i][j] == -2)
					cost2 += 5;
			}
	}
	if(cost2 > cost1)
		return cost1;
	else 
		return cost2;
}

int main()
{
	int f,t;
	scanf("%d",&t);
	
	for(f=0;f<t;f++)
	{
		int m,n,i,j;
		scanf("%d%d",&n,&m);
		
		char a[100][100];
		for(i=0;i<n;i++)
			scanf(" %[^\n]",a[i]);


		int b[100][100];
		int c[100][100],d[100][100];
		int f1=-1,f2=1;
		for(i=0;i<n;i++)
		{	
			f1 =f1*(-1);
			f2 =f2*(-1);
			int flage1=f1,flage2=f2;
			for(j=0;j<m;j++)
			{
				
				if(a[i][j]=='R')
					b[i][j]=-1;
				if(a[i][j]=='G')
					b[i][j]=1;
				c[i][j] = flage1;
				d[i][j] = flage2;
				flage2 = flage2*(-1);
				flage1 = flage1*(-1);
			}
	
		}
		printf("%d\n",cost(b,c,d,n,m));
	}
	return 0;
}
