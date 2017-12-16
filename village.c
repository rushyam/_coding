#include <stdio.h>
#include <stdlib.h>
int last(char s[],int i)
{
	int j;
	for(j=i;;j++)
		if(s[j+1]!= '.' || s[j+1] == '\0')
			return j;
}
int count_a(char s[],int i)
{
	int j,count = 0;
	for(j=i;s[j]!='\0';j++)
		{
			if(s[j] == 'A')
				return count;
			count++;
		}
	return 0; 
}
int count_b(char s[],int i)
{
	int j,count = 0;
	for(j=i;s[j]!='\0';j++)
		{
			if(s[j] == 'B')
				return count;
			count++;
		}
	return 0; 
}
int main()
{
	int f,t;
	scanf("%d",&t);
	printf("sonu\n");
	for(f=0;f<t;f++)
	{	
		printf("rushyam\n");
		char *s = (char*)malloc(50*sizeof(char));
		fflush(stdin);
		gets(s);
		int i,c_a=0,c_b=0,flag_a=0,flag_b=0;
		for(i=0;s[i]!='\0';i++)
		{
			if(s[i] == 'A')
				{
					c_a++;
					flag_a = 1;
					flag_b = 0;
				}
			if(s[i] == 'B')
				{
					c_b++;
					flag_a = 0;
					flag_b = 1;
				}
			if(s[i] == '.' && flag_a == 1)
				{
					c_a += count_a(s,i);
					i = last(s,i);
				}
			if(s[i] == '.' && flag_b == 1)
				{
					c_b += count_b(s,i);
					i = last(s,i); 
				}
		}
		printf("%d %d\n",c_a,c_b);
	}
return 0;
}