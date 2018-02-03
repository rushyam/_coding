#include <stdio.h>
#include <stdlib.h>
int main()
{
	int f,t;
	scanf("%d",&t);
	for(f=0;f<t;f++)
	{
		int n, m, x, k;
		scanf("%d %d %d %d",&n, &m, &x, &k);
		char *s = (char *)malloc(k+1);
		scanf("%s",s);
		int i,count_odd=0,count_even=0;
		for(i=0; s[i]!= '\0'; i++)
		{
			if(s[i] == 'O')
				count_odd++;
			if(s[i] == 'E')
				count_even++;
		}
		int c_o,c_e;
		for(i=1;i<=m;i++)
		{
			if(i%2 == 0 && count_even > 0)
			{
				c_e = count_even > x ? x : count_even;
				count_even -= c_e;
				n -= c_e;  
			}
			if(i%2 == 1 && count_odd > 0)
			{
				c_o = count_odd > x ? x : count_odd;
				count_odd -= c_o;
				n -= c_o;  
			}
		}
		if (n<=0)
			printf("yes\n");
		if (n > 0)
			printf("no\n");
	}
	return 0;
}