#include <stdio.h>
#include <stdlib.h>
int used; 
int jump(int *h,int n,int u,int d,int p)
{
	// printf("function\n");
	if(p>=n-1)
		return p;
	if(h[p+1] >= h[p] && h[p+1] - h[p] <=u)
	{
		p++;
		// printf("up%d\n",p);
		p=jump(h,n,u,d,p);
	}
	else if(h[p] - h[p+1] <=d && h[p] > h[p+1] )
	{
		p++;
		// printf("down%d\n",p);
		p=jump(h,n,u,d,p);
	}
	else if(h[p] - h[p+1] >d && used == 0 &&  h[p] > h[p+1])
	{
		p++;
		used = 1;
		// printf("used\n");
		p=jump(h,n,u,d,p);
		
	}
	else if(h[p+1] - h[p] >u || h[p] - h[p+1] <d)
		{// {printf("aaaaaa%d\n",p );
		return p;
		}
		return p;
}
int main()
{
	int f,t,i;
	scanf("%d",&t);
	for(f=0;f<t;f++)
	{
		used = 0;
		int n,u,d,p=0;
		scanf("%d%d%d",&n,&u,&d);
		int *h= (int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
			scanf("%d",&h[i]);
		printf("%d\n",jump(h,n,u,d,p)+1);
	}
	return 0;
}