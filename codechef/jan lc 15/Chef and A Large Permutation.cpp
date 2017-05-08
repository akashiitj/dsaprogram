#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;
const int N = 10000001;
const int mod = 1000000007;
ull a[1000000];
ull s[1000000];
ull sut(ull n)
{
    return (n*(n+1))/2;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    ull n,k;
    while(t--)
    {
        s[0]=0;
        cin>>n>>k;
        loop(i,0,k)
        {
            cin>>a[i];

        }
        sort(a,a+k);
        loop(i,0,k)
        {

            s[i+1]=s[i]+a[i];
        }
        ull x;
        ull v=0;
        loop(i,0,k)
        {
            x=sut(a[i])-s[i+1]+1;//this is first number y cant make
            if(x<=a[i])//but if x is >a[i] may be it is present further but if not it cant be formed
            {
                v=1;
                break;
            }
        }
        //cout<<x<<endl;
        if(v==1)
        {
            if(x%2!=1)cout<<"Mom"<<endl;
            else cout<<"Chef"<<endl;
        }
        else
        {
            x=sut(n)-s[k]+1;
            if(x%2!=1)cout<<"Mom"<<endl;
            else cout<<"Chef"<<endl;
        }
    }
    return 0;
}

