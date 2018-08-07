#include<iostream>
#include<limits.h>
using namespace std;
int main()
 {
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int *a= new int[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int **t = new int*[n-1];
        for(int i=0;i<n-1;i++)
            t[i] = new int[n-1];
        int i=0,j=0,k=0;
        while(k<n-1)
        {
            while(j<n-1)
            {
                if(i == j)
                    t[i][j] = 0;
                else if(i+1 == j)
                    t[i][j] = a[i]*a[j]*a[j+1];
                else
                {
                    int m = INT_MAX;
                    for(int k=i;k<j;k++)
                        m = min(m,t[i][k]+t[k+1][j] + a[i]*a[k+1]*a[j+1]);
                    t[i][j] = m;
                }
                i++;
                j++;
            }
            k++;
            j=k;
            i=0;
        }
        cout<<t[0][n-2]<<endl;
    }
	return 0;
}
