#include <stdio.h>
int main()
{
	int f,t;
	scanf("%d",&t);
	for(f=0;f<t;f++)
	{
		int a[4];
		int i,j;
		for(i=0;i<4;i++)
			scanf("%d",&a[i]);

		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				if(i!=j && a[i] == a[j])
					{
						a[i]=-1;
						a[j]=-1;
					}
		j=0;
		for(i=0;i<4;i++)
			{
				if(a[i]!=-1)
				{
					printf("NO\n");
					break;
				}
				j++;
			}
		if(j==4)
			printf("YES\n");
	}

	return 0;
}