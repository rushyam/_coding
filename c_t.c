#include <stdio.h>
#include <stdlib.h>
int table(float **x,int c,int n,float d, float s,int a[])
{
	int i,j;
	for(i=1;i<c;i++)
		for(j=1;j<n;j++)
		{
			float z = x[i][j-1] + d/s ;
			float w = x[i-1][j] - a[j];
			float y = z-w > a[j] ? a[j] : a[j] + a[j] - z + w;
			// printf("%f\t%f\t%f\n",z,w,y); 		
			x[i][j] = z + y;
		}
}
int main()
{	
	int f,t;
	scanf("%d",&t);
	for(f=0;f<t;f++)
	{
		int n,c,i,j;
		float d,s;
		scanf("%d",&n);
		int *a = (int *)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
			scanf("%d", &a[i]);
		scanf("%d%f%f",&c,&d,&s);
		float **x = (float **)calloc(c,sizeof(float *));
		for(i=0;i<c;i++)
			x[i] = (float *)calloc(n,sizeof(float));
		for(i=0;i<c;i++)
			x[i][0] = (i+1)*a[0];
		for(i=1;i<n;i++)
			x[0][i] = x[0][i-1] + d/s + a[i];
		table(x,c,n,d,s,a);
		for(i=0;i<c;i++)
		{
			for(j=0;j<n;j++)
				printf("%f\t", x[i][j]);
			printf("\n");
		}
		float wait = x[c-1][n-1] - x[0][n-1];
		printf("%f\n",wait);

	}
	return 0;
}