#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;
const int N = 10000001;
const int mod = 1000000007;
int gcd(int a, int b)
{

    if(b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}
int f[100001];
int r[100001];
int a[100001];
int main()
{
    //cout<<gcd(9,2);
    std::ios_base::sync_with_stdio(false);
    int t,q,n,g,h,y,u;
    cin>>t;
    int x=1;
    //f[0]=1;
    while(t--)
    {
        cin>>n>>q;
        r[n+1]=1;
        loop(i,0,n)
        {
            cin>>a[i];
            //  f[i+1]=gcd(a[i],f[i]);
        }
        f[0]=a[0];
        loop(i,1,n)
        {
            //cin>>a[i];

            f[i]=gcd( f[i-1], a[i]);
        }

        r[n-1]=a[n-1];
        for(int j=n-2; j>=0; j--)
        {

            r[j]=gcd(r[j+1],a[j]);
            // r[j]=gcd(r[j+1],a[j]);
        }

        loop(i,0,q)
        {
            cin>>g>>h;
            g--;
            h--;
            g--;
            h++;
            if(g<0)
            {
                cout<<r[h]<<endl;
                continue;
            }
            if(h>=n)
            {
                cout<<f[g]<<endl;
                continue;
            }

            cout<<gcd(f[g],r[h])<<endl;
        }


    }
    return 0;
}

