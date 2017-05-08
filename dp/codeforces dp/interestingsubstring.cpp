#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#define mx 100006
long long sum[mx];
char ar[mx];
map<long long , int> m[26];
long long v[27];
int main()
{
    for(int i=0; i<26; ++i)
        cin>>v[i];
    scanf("%s",ar+1);
    long long ans=0;
    sum[0]=0;

    for(int i=1; ar[i]; ++i)
    {
        sum[i]=sum[i-1]+ v[ar[i]-'a'];
        cout<<sum[i]<<" sumi\n";
        cout<<sum[i-1]<<" sumi pre\n";
        cout<<m[ar[i]-'a'][sum[i-1]]<<" map\n\n";

        ans+=m[ar[i]-'a'][sum[i-1]];
        m[ar[i]-'a'][sum[i]]++;
    }
    cout<<ans<<endl;
}
