#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define em push
#define X first
#define Y second
#define all(v)                      v.begin(),v.end()
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define _ ios::sync_with_stdio(false);cin.tie(0);

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define endl '\n'
#define MAX 100010
#define MOD 1000000007
LL N,mem[20][170][1500],str[20];
LL solve(int idx,int sum,int sqr,int end)
{
    if(idx == -1)
        return __gcd(sum,sqr) == 1;

    LL& ans = mem[idx][sum][sqr];
    if(!end && ans != -1)	return ans;

    LL res = 0;
    int range = end?str[idx]:9;
    for(int i=0; i<=range; i++)
        res += solve(idx-1,sum+i,sqr + i*i,end && (str[idx] == i));

    return end?res:(ans = res);
}
LL calc(LL n)
{
    int L = 0;
    while(n)
    {
        str[L++] = n%10;
        n/=10;
    }
    return solve(L-1,0,0,1);
}
int main()
{
    _
    memset(mem,-1,sizeof mem);
    int t;
    LL L,R;
    cin>>t;
    while(t--)
    {
        cin>>L>>R;
        cout<<calc(R) - calc(L-1)<<endl;
    }
    return 0;
}
