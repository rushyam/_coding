#include <stdio.h>
#include <stdlib.h>
int yes(char b[])
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(b[i] < b[j])
			{
				char temp =b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}
	if(b[0] == 'c' && b[1] == 'e' && b[2] == 'f' && b[3] == 'h')
		return 1;
	return 0;
}
int main()
{
	int f,t;
	scanf("%d",&t);
	for(f=0;f<t;f++)
	{
		char *a = (char *)malloc(500000);
		scanf("%s",a);
		char b[4];
		int i,j,count=0,k;
		for(i=0;a[i+3]!='\0';i++)
		{
			for(k=0;k<4;k++)
				b[k] = a[i+k];
			if(yes(b) == 1)
				count ++;
		}
		if(count == 0)
			printf("normal\n");
		if(count > 0)
			printf("lovely %d\n", count);
	}
	return 0;
}