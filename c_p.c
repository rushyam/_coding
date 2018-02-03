#include <stdio.h>
#include <stdlib.h>
int main()
{
	int f,t;
	scanf("%d",&t);
	for(f=0;f<t;f++)
	{
		int n,m,x,k;
		scanf("%d%d%d%d",&n,&m,&x,&k);
		char *s= (char *)malloc(k);
		int c[2],i;
		c[0]=0;
		c[1]=0;
		scanf("%s",s);
		for(i=0;s[i]!='\0';i++)
		{
			if(s[i] == 'E')
				c[1]++;
			if(s[i] == 'O')
				c[0]++;
		}
		int flag = 0;
		int c_o = c[0],c_e = c[1];
		for(i=1;i<=m;i++)
		{
			c[1] = c_e>x?x:c_e;
			c[0] = c_o>x?x:c_o;	
			if(c[1] < 0)
				c[1] = 0;
			if(c[0] < 0)
				c[0] = 0;
			n = n - c[i%2];
			c_o -= c[0]; 
			c_e -= c[1];
			if(n == 0)
				flag = 1;
		}
		if(flag == 1)
			printf("yes\n");
		if(flag == 0)
			printf("no\n");		
	}
	return 0;
}