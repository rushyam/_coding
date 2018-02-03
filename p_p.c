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
		int *a = (int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
			a[i] = i+1;
		quick(s,a,0,n-1);
		int flag = 1;
		if(n%2 == 0)
		{
			for(i=0;i<n-1;i += 2)
			{
				if(s[i]!=s[i+1])
				{
					flag = 0;
					break;
				}
			}
		}
		// printf("%s",s);
		// for(i=0;i<n;i++)
		// 	printf("%d \t",a[i]);
		if(flag==0)
		{
			printf("-1\n");
			continue;
		}
		flag=0;
		if(n%2)
		{
			for(i=0;i<n-1;)
			{
				if(s[i]!=s[i+1])
				{
					flag++;
					i++;
				}
				else i+=2;
			}
		}
		if(flag>1)
		{
			printf("-1\n");
			continue;
		}

		if(n%2==0)
		{
			for(i=1;i<n/2;i+=2)
			{
				char temp=s[i];
				s[i]=s[n-i];
				s[n-i]=temp;
				int temp2=a[i];
				a[i]=a[n-i];
				a[n-i]=temp2;
			}	
			for(i=0;i<n;i++)
				printf("%d ",a[i]);
			printf("\n");
			continue;
		}
		i=0;
		while(i<n)
		{
			if(s[i]!=s[i+1])
				break;
			i+=2;
		}
		if(i<=n/2)
		{
			char temp=s[i];
			int temp2=a[i];
			int j=i;
			while(j<n/2)
			{
				s[j]=s[j+1];
				a[j]=a[j+1];
				j++;
			}
			s[j]=temp;
			a[j]=temp2;
		}
		else
		{
			int temp2=a[i];
			char temp=s[i];
			int j=i;
			while(j>n/2)
			{
				a[j]=a[j-1];
				s[j]=s[j-1];
				j--;
			}
			a[j]=temp2;
			s[j]=temp;	
		}


		for(i=1;i<n/2;i+=2)
			{
				char temp=s[i];
				s[i]=s[n-i];
				s[n-i]=temp;
				int temp2=a[i];
				a[i]=a[n-i];
				a[n-i]=temp2;
			}

		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
		continue;

	}
	return 0;
}