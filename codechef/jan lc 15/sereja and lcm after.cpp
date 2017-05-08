#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int expp, n, m;
inline long long poww(long long y)
{
    long long x = 1;
    while(expp)
    {
        if(expp&1)
        {
            x *= y;
            if(x > MOD)
                x %= MOD;
        }
        y = y*y;
        if(y > MOD)
            y %= MOD;
        expp>>=1;
    }
    return x;
}
int arr[1001][4];
int c[1001];
void factorise()
{
    int rt;
    for(int i = 1; i<1001; i++)
    {
        rt = sqrt(i)+1;
        int t = i;
        for(int j = 2; j<rt; j++)
        {
            if(t%j==0)
            {
                int ans = 1;
                while(t%j==0)
                {
                    t = t/j;
                    ans = ans*j;
                }
                arr[i][c[i]++] = ans;
            }
        }
        if(t!=1)
            arr[i][c[i]++] = t;
    }
}
int mx;
int curr;
long long fn(int val, int cn, int sn)
{
    if(cn==mx)
    {
        int cnt = 0;
        int nf[1001];
        memset(nf, 0, sizeof nf);
        for(int i = 0; i<c[val]; i++)
        {
            int temp = arr[val][i];
            for(int j = temp; j<=m; j+=temp)
                nf[j] = 1;
        }
        for(int i = 1; i<=m; i++)
            if(nf[i]==0)
                cnt++;
        expp = n;
        long long ans = poww(cnt);
        if(sn%2==1)
            return MOD-1*ans;
        else
            return ans;
    }
    long long a1 = fn(val*arr[curr][cn], cn+1, sn+1);
    long long a2 = fn(val, cn+1, sn);
    a1 = a1+a2;
    if(a1>MOD)
        a1 = a1%MOD;
    return a1;
}
int main()
{
    int t, l, r;
    factorise();
    for(int i=1;i<=10;i++)
        cout<<i<<" "<<arr[i][0]<<" "<<arr[i][1]<<" "<<arr[i][2]<<" "<<arr[i][3]<<" "<<c[i]<<endl;
    scanf("%d", &t);
    for(;t--;)
    {
        scanf("%d%d%d%d", &n, &m, &l, &r);
        expp = n;
        long long temp_n = poww(m);
        long long ans = 0;
        long long temp, temp2;
        int a;
        for(int i = l; i<=r; i++)
        {
            mx = c[i];
            curr = i;
            temp = fn(1, 0, 0);
            //cout<<temp<<endl;
            ans+=temp;
        }
        if(ans>MOD)
            ans%=MOD;
        if(ans<0)
            ans+=MOD;
        printf("%lld\n", ans);
    }
}
