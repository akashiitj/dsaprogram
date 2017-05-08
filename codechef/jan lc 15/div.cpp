#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i = a; i < b; i++)

typedef long long ll;
typedef double d;
typedef unsigned long long ull;
const int N = 10000001;
const int mod = 1000000007;

int main()
{
    std::ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    double sum=0.0,x,c;
    int n;
    while(t--)
    {   sum=0.0;
       c=0;
        cin>>n;
        loop(i,0,n)
        {
            cin>>x;
            sum=sum+x;
            if(x==0)c++;
        }

    d dif=sum-100.0;
   // cout<<dif<<endl;
    if(dif<0.0)
    {
        cout<<"NO"<<endl;
        continue;
    }
    if(dif<n-c&&dif>=0.0)
    {
        cout<<"YES"<<endl;
        continue;
    }
    cout<<"NO"<<endl;
}
return 0;
}
