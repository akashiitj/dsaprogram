#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<bitset>
#include<functional>
#include<utility>

using namespace std;

typedef long long llint;
typedef pair<int,int> ipair;
#define fi first
#define se second
#define mp make_pair

void read(int &k)
{
    k=0;
    char x=getchar();
    while(x<'0'||x>'9') x=getchar();
    while(x>='0'&&x<='9')
    {
        k=k*10-48+x;
        x=getchar();
    }
}

int n,x,ans,f[100010],out;

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&x);
        ans=0;
        for(int i=2; i*i<=x; i++) if (x%i==0)
            {
                ans=max(ans,f[i]);
                ans=max(ans,f[x/i]);
            }
        ans++;
        for(int i=1; i*i<=x; i++) if (x%i==0)
            {
                f[i]=ans;
                f[x/i]=ans;
            }
        if (ans>out) out=ans;
    }
    cout<<out<<endl;

    return 0;
}
