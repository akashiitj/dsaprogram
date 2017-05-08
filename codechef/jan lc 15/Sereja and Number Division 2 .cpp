#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;
const int N = 10000001;
const int mod = 1000000007;
//char c[1000];
ll ba[1000];
ll max1=1000000007,max2=0;
string ansa;
void permute(string a,int i, int n,int bas)
{
    int j;
    if (i == n)
    {
        max2=0;
        ll sa=atoi(a.c_str());
        loop(g,0,bas)
        {
            max2=max2+sa%ba[g];
        }
        if(max2<max1)
        {
            max1=max2;
            ansa=a;
        }
    }
    else
    {
        for (j = i; j <= n; j++)
        {
            swap(a[i],a[j]);
            permute(a, i+1, n,bas);
            swap(a[i],a[j]);
        }
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    int t,n,x;
    string s;
    cin>>t;
    ll na[10];
    while(t--)
    {
        loop(i,0,10)
        na[i]=0;
        cin>>s;
        cin>>n;
        int l=s.length();
        loop(i,0,n)
        cin>>ba[i];
        loop(i,0,l)
        na[s[i]-48]++;

        vector<int> v;
       int c=0;

        loop(i,0,10)
        {
            if(na[10-i-1]!=0)
            {
                v.push_back(10-i-1);
                na[10-i-1]--;
                c++;
            }
           // if(c==6)break;
        }

        string s;
        loop(i,0,v.size())
        {
            char c=48+v[i];
            s.push_back(c);
        }
        //      cout<<s<<" s "<<endl;
        max1=1000000007;
        if(s.length()<=6)permute(s,0,s.length()-1,n);
        else permute(s,s.length()-6,s.length()-1,n);
        string s2;

        loop(i,0,10)
        {
            //cout<<na[i]<<" "<<i<<endl;
            while(na[10-i-1]!=0)
            {
                char ds=10-i-1+48;
                s2.push_back(ds);
                na[10-i-1]--;
            }

        }
        s2.append(ansa);
        cout<<s2<<endl;
    }
    return 0;
}
