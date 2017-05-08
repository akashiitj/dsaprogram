#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;
const int N = 10000001;
const int mod = 1000000007;

int main()
{   std::ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    string s;
    int li=0;
    int si=0;
    int max1,min1;
   for(int h = 1; h <= t; h++)
    {
        cin>>s;
        string s1=s;
        max1=s[0];
        min1=s[0];
        loop(i,0,s.length())
        {
            if(s[i]>=max1)
                {li=i;max1=s[i];}
            if(s[i]<=min1&&s[i]!=48)
                {si=i;min1=s[i];}
        }
        swap(s1[0],s1[si]);
        swap(s[0],s[li]);
        cout<<"Case #"<<h<<": "<<s1<<" "<<s<<endl;
    }
    return 0;
}

