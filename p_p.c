#include <stdio.h>
#include <stdlib.h>
int quick_sort(char s[],int a[],int l,int r)
{
	int i,j = l-1;
	char temp = s[r];
	for(i=l;i<r;i++)
	{
		if(temp > s[i])
		{
			j++;
			char t;
			int te;
			t = s[j];
			te = a[j];
			a[j] = a[i];
			s[j] = s[i];
			s[i] = t;
			a[i] = te;
		}
	}
	j++;
	char t;
	int te;
	t = s[j];
	te = a[j];
	a[j] = a[r];
	s[j] = s[r];
	s[r] = t;
	a[r] = te;
	return j;
}
int quick(char s[],int a[],int l,int r)
{
	if(l<r)
	{
		int k = quick_sort(s,a,l,r);
	
		quick(s,a,l,k-1);
		quick(s,a,k+1,r);
	}
	return 0;
}
int main()
{
	int f,t;
	scanf("%d",&t);
	for(f=0;f<t;f++)
	{
		char *s = (char *)malloc(100001);
		scanf("%s",s);
		int i,n;
		for(i=0;s[i] != '\0';i++)
			n=i;
		n=n+1;
		printf("%d\n", n);
		int *a = (int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
			a[i] = i+1;
		quick(s,a,0,n-1);
		for(i=0;i<n;i++)
			printf("%d\n",s[i] );; 
	}
	return 0;
}