#include <stdio.h>
int compare(char a[100000][21],char b[21],int i)
{
	int j;
	for(j=0;a[i][j]!='\0';j++)
		if(b[j] != a[i][j])
			return 1;
	return 0;
}
int main()
{
	int f,t;
	scanf("%d",&t);
	for(f=0;f<t;f++)
	{
		int n,i,j,count1=0,count2=0;
		
		scanf("%d",&n);
		
		char a[100000][21];
		char t1[21],t2[21];

		int f1=0,f2=0;
		for(i=0; i<n ; i++)
			{
				scanf("%s",a[i]);
				if(f1 == 0)
				{
					for(j=0;a[0][j]!='\0';j++)
					{
						t1[j]=a[0][j];
						t1[j+1]='\0';
					}
					f1=1;
				}
				if(compare(a,t1,i)==0)
					count1++;
				if(compare(a,t1,i)==1)
				{
					if(f2==0)
					{
						for(j=0;a[i][j]!='\0';j++)
						{
							t2[j]=a[i][j];
							t2[j+1]='\0';
						}
						f2=1;
					}
					count2++;
				}
			}
		if(count1>count2)
			printf("%s\n",t1);
		if(count2>count1)
			printf("%s\n",t2);
		if(count2==count1)
			printf("Draw\n");
	}
	return 0;
}