#include<bits/stdc++.h>
using namespace std;
int main()
{
    float n,a,b;
    cin>>n>>a>>b;
    long long d=6*n-(a*b);
    if(d<=0)
    {
        cout<<(long long)a*(long long)b<<endl;
        cout<<(long long)a<<" "<<(long long)b<<endl;
        return 0;
    }
    if(ceil(d/a)*a<=ceil(d/b)*b)b=b+ceil(d/a);
    else a=a+ceil(d/b);
    cout<<(long long)a*(long long)b<<endl;
    cout<<(long long)a<<" "<<(long long)b<<endl;
    return 0;

}
