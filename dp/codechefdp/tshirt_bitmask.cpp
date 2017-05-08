#include <algorithm>
#include <string.h>
#include <stdio.h>
#define  maxn      101
#define  maxb      1024
#define  mod       1000000007
using    namespace std;

int T,n;
int ar[maxn];
int dp[maxn][maxb];

void Reset()
{
    memset(ar,0,sizeof(ar));
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
}

int main()
{
    char s[500];
    scanf("%d",&T);
    while(T--)
    {
        Reset();
        scanf("%d\n",&n);
        for(int i=0 ; i<n ; i++)
        {
            gets(s);
            int len=strlen(s);
            for(int l=0 ; l<len ; l++)
            {
                int x=0,r=l;
                while(r<len && s[r]>='0' && s[r]<='9')
                {
                    x*=10;
                    x+=s[r]-'0';
                    r++;
                }
                ar[x]|=(1<<i);
                l=r;
            }
        }
        for(int i=1 ; i<=100 ; i++)
        {
            for(int k=0 ; k<(1<<n) ; k++)
                dp[i][k]=dp[i-1][k];
            for(int k=0 ; k<(1<<n) ; k++)
            for(int j=0 ; j<n ; j++)
                if(ar[i]&(1<<j))
                   if(k&(1<<j))
                            dp[i][k]=(dp[i][k]+dp[i-1][k-(1<<j)])%mod;
        }

        for(int i=0 ; i<=100 ; i++)
        {
            for(int k=0 ; k<(1<<n) ; k++)
                printf("%d ",dp[i][k]);
            printf("\n");
        }
        printf("%d\n",dp[100][(1<<n)-1]);
    }
    return 0;
}
