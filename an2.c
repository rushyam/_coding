#include <stdlib.h>
#include <stdio.h>
void merge(int arr[], int l, int m, int r,int d[])
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 	int ld[n1],rd[n2];
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
       {
        L[i] = arr[l + i];
        ld[i] = d[l+i];
    	}
    for (j = 0; j < n2; j++)
        {
        	R[j] = arr[m + 1+ j];
        	rd[j] = d[m+1+j];
 		}
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
        {
            arr[k] = L[i];
            d[k] = ld[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            d[k] = rd[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        d[k] = ld[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        d[k] = rd[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r,int d[])
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m,d);
        mergeSort(arr, m+1, r,d);
 
        merge(arr, l, m, r,d);
    }
}
int sum(int d[],int l,int r)
{
	int i,count =0;
	for(i=l;i<=r;i++)
		count += d[i];
	// printf("%d\t%d\t%d\n",l,r,count);
	return count;
}
int sum_mul(int a[],int d[],int lc,int rc)
{

int i,count=0;
for(i=lc;i<=rc;i++)
	count += a[i]*d[i];
	return count;
}
int print(int a[],int d[],int lc,int rc)
{
	int i,j;
	for(i=lc;i<=rc;i++)
	{
		for(j=0;j<d[i];j++)
			printf("%d\t",a[i]);
	}
	printf("\n");
}
int main()
{
	int f,t;
	scanf("%d",&t);
	for(f=0;f<t;f++)
	{
		int n,k,i;
		scanf("%d%d",&n,&k);
		int *a =(int *)malloc(n*sizeof(int));
		int *d =(int *)malloc(n*sizeof(int));
		int *b =(int *)malloc(k*sizeof(int));
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			scanf("%d",&d[i]);
		for(i=0;i<k;i++)
			scanf("%d",&b[i]);
		mergeSort(a, 0, n-1, d);
		int lc=0,rc=n-1;
		// print(a,d,0,n-1);
		for(i=0;i<k;i++)
		{
			
			b[i] = sum(d,lc,rc) - b[i]; 
			if((i)%2 ==1)
			{
			while(1)
			{if(b[i] >= d[lc])
			{
				// print(a,d,lc,rc);
				b[i] -= d[lc];
				lc++; 
				if(d[lc] > b[i])
				{
					d[lc] -= b[i];
					break;
				}
			}
			}}
			if((i)%2==0)
			{
				// print(a,d,lc,rc);
				while(1)
				{
					if(b[i] >= d[rc])
					{
						b[i] -= d[rc];
						rc--;
						if(d[rc] > b[i])
						{
							d[lc] -=b[i];
							break;
						}
					}
				}
			}

		}

		// print(a,d,lc,rc);
		printf("%d\n", sum_mul(a,d,lc,rc));



	}
	return 0;
}