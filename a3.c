#include <stdio.h>
#include <stdlib.h>
extern int registerme ( int );
extern void startsort ( );
extern int compareballs ( int, int );
extern void verifysort ( int * );
extern void startmatch ( int );
extern int fitsin ( int i, int j );
extern void verifymatch ( int * );
void merge(int s[],int l,int m,int r)
{
	int n1=m-l+1,n2=r-m;
	int i,j,k,c;
	int *s_l = (int *)malloc(n1*sizeof(int));
	int *s_r = (int *)malloc(n2*sizeof(int));
	for(i=0;i<n1;i++)
		s_l[i] = s[l+i];

	for(i=0;i<n2;i++)
		s_r[i] = s[m+1+i];

	i=0,j=0,k=l;

	while(i<n1 && j<n2)
	{
		c = compareballs(s_l[i],s_r[j]);
		if(c==1)
		{
			s[k]=s_r[j];
			j++;
		}
		if(c==-1)
		{
			s[k]=s_l[i];
			i++;
		}
		k++;
	}
	while(i<n1)
	{
		s[k]=s_l[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		s[k]=s_r[j];
		j++;
		k++;
	}
}
void merge_sort(int s[],int l,int r)
{
	if(l<r)
	{
		int m = (l+r)/2;
		merge_sort(s,l,m);
		merge_sort(s,m+1,r);
		merge(s,l,m,r);
	}
}
int count = 0;
int partition(int s[],int m[],int l,int r)
{

	int mid =(l+r)/2;
	int *a = (int *)malloc(sizeof(int)*(r-l+1));
	int i,c,j = 0, k = r - l , p;
	for (i = l; i <= r; i++)
	{
		// printf("%d\n",count );
		c = fitsin(s[mid],m[i]);
		// count++;
		if(c == -1)
		{
			a[j] = m[i];
			j++;
			// sprintf("-1:%d\n", m[i]);
		}
		if(c == 1)
		{
			a[k] = m[i];
			k--;
			// printf("1:%d\n", m[i]);
		}
		if(c == 0)
		{	
			p = m[i];
			// printf("0:%d\n", m[i]);
		}
	}

	a[j] = p;
	
	printf("\n");
	for(i =l;i<=r;i++)
	{		
		m[i] = a[i-l];
		// printf("%d\t", a[i-l]);
	}
	return j;
}
int quick_sort(int s[],int m[],int l,int r)
{
	if(l<r)
	{
		int p;
		p = partition(s,m,l,r);
		printf("%d\t%d\t%d\n",l,p,r );	 
		quick_sort(s,m,l,p);
		quick_sort(s,m,p+1,r);
	}
}
int main()
{
	int n = 10,i,j;
	int *s = (int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		s[i]=i;
	registerme(n);
	
	printf("\n+++ Sorting the balls...\n");
	startsort();

	merge_sort(s,0,n-1);

	verifysort(s);
	int *N = (int *)malloc(n*sizeof(int));
	int *m = (int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		m[i]=i;
	printf("\n+++ Finding the matching boxes...\n");
	startmatch(0);

	quick_sort(s,m,0,n-1);
	

	for(i=0;i<n;i++) //For rearranging boxes with respect to balls.
	{
		for(j=0;j<n;j++)
		{
			if(fitsin(s[i],m[j])==0) N[i] = m[j];
		}
	}
	
	verifymatch(m);
}