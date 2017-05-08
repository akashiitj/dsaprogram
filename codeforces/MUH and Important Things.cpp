#include<bits/stdc++.h>
using namespace std;
unsigned long long fa(unsigned long long n)
{
    unsigned long long fact=1.0;
    for(unsigned long long i=n ; i>=1 ; i--)
        fact = fact*i;
    return fact;
}
void p( vector<pair<unsigned long long ,unsigned long long> > v,unsigned long long n)
{
    for(unsigned long long i=0; i<n; i++)
        cout<<v[i].second<<" ";
    cout<<endl;
}
int main()
{
    vector<pair<unsigned long long ,unsigned long long> > v;
    unsigned long long n;
    cin>>n;
    unsigned long long x=1,f=1,i;
    for(unsigned long long i=1; i<=n; i++)
    {

        cin>>x;
        v.push_back(make_pair(x,i));
    }
    sort(v.begin(),v.end());
    for( i=1; i<n; i++)
    {
        x=1;
        while(v[i].first==v[i-1].first)
        {
            // cout<<i<<" i "<<endl;
            x++;
            i++;
        }
        //cout<<x<<" "<<f<<endl;

        f=f*fa(x);
        // i++;

    }
    if(f>=3)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
        return 0;
    }
    x=1;
    i=1;
    p(v,n);
    while(x<3&&i<n)
    {
        if(v[i].first==v[i-1].first)
        {
            swap(v[i],v[i-1]);
            p(v,n);
            x++;
        }
        i++;

    }
    return 0;
}
