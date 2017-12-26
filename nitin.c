#include <stdio.h>
int check(char *a,int i)
{
	if(*a-97 == i)
		printf("fuck off\n");
}
int main()
{
	int i,j,c[10];
	for(i=0;i<10;i++)
		c[i]=0;
	char temp1,temp2;
	for(i=0;i<10;i++)
	{
		scanf("%c%c",&temp1,&temp2);
		check(&temp1,i);
		check(&temp2,i);
		c[temp1-97]++;
		c[temp2-97]++;
	}
	for(i=0;i<10;i++)
		printf("%c = %d\n",(97+i),c[i] );
return 0;
}