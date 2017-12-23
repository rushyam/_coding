#include <stdio.h>
void print(int a[])
{
	int j;
	for(j=0;j<10;j++)
		printf("%d", a[j]);
	printf("\n");
}
int sum(int a[])
{
	int i,count=0;
	for(i=0;i<10;i++)
		count += a[i];
	if(count == 10)
		return 1;
	return 0;
}
int check(int a[])
{
	int b[10];
	int i,j;
	for(i=0;i<10;i++)
	{
		b[i]=0;
		for(j=0;j<10;j++)
		{
			if(a[j]==i)
				b[i]++;
		}
	}
	int count=0;
	for (int i = 0; i < 10; ++i)
	{
		if(a[i]==b[i])
			count++;
	}
	if(count == 10)
		return 1;
	return 0;
}
int c=0;
int number(int a[])
{
	if(c==9)
	{
		int j;
		for(j=0;j<10;j++)
			{
				a[c]=j;
				if(sum(a) == 0)
					return 0;
				if(check(a) == 1)
					print(a);
			}
	}
	else
	{
		int j;
		for(j=0;j<10;j++)
		{
			a[c] = j;
			c++;
			number(a);
			c--;
		}
	}
	return 0;
}
int main()
{

	int a[10];
	number(a);
	return 0;
}