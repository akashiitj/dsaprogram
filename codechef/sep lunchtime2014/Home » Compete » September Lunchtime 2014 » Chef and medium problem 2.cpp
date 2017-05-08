#include <bits/stdc++.h>
using namespace std;

int main()
{    ios_base::sync_with_stdio(false);
    long long n;
    cin>>n;
    unsigned long long a[n];
    for(long long i=0;i<n;i++)
        cin>>a[i];
    long long m;
    cin>>m;

    for(long long i=0;i<m;i++)
    {
        long long j;
        cin>>j;
        if(j==1)
        {
            long long l,r;
            unsigned long long p;
            cin>>l;
            cin>>r;
            cin>>p;
            for(long long x=l-1;x<=r-1;x++)
            {
                if((a[x]%p)==0)a[x]=a[x]/p;
            }
        }
       else if(j==2)
        {   long long l;
         unsigned long long d;
            cin>>l;
            cin>>d;
            a[l-1]=d;

        }
    }
    for(long long i=0;i<n;i++)
        cout<<a[i]<<" ";
        cout<<endl;
return 0;
}
