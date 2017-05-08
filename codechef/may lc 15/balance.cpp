#include<bits/stdc++.h>
using namespace std;

typedef int  ll;
typedef unsigned long long  ull;

#define fast      ios_base::sync_with_stdio(false)
#define frmlty     int test_case;cin>>test_case;while(test_case--)

int dp[27][100001];
string s;
int Q;
int N;

#define loop(i,a,b)      for(ll i=a;i<b;i++)

ll fast_mul(ll A,ll pow)
{
    ll C=1;


    while(pow>0)
    {
        if(pow&1)
        {
            C=C*A;

            // cout<<C<<" "<<mod1(A)<<endl;
        }
        A=A*A;

        pow>>=1;
    }
    return C;
}



int solve(int l,int r,int type)
{   int bo=1;
    int ans=0;
    loop(i,l,r)
    {
        loop(j,i+1,r+1)
        {   bo=1;
            loop(x,0,26)
            {
                if(((dp[x][j]-dp[x][i-1])%2)!=0)bo=0;
                //cout<<dp[x][j]<<" "<<dp[x][i-1]<<endl;
            }
            if(bo==1)
            {  // cout<<j-i+1<<" "<<type<<" "<<fast_mul(j-i+1,type)<<endl;
                ans=ans+fast_mul(j-i+1,type);
            }
        }
    }
   // cout<<ans<<endl;
    return ans;

}


void decode(){
    int X,Y,type,L,R,T,A,B,ans;
    A = 0 ; // initialising first key
    B = 0 ; // initialising second key
    scanf("%d",&Q);// number_of_queries;
    while( Q -- ) {
       scanf("%d%d%d",&X,&Y,&type);

        L = ( X + A ) % N + 1; // decoding L
        R = ( Y + B ) % N + 1; // decoding R
        // N is the length of the given string
        if (L > R) {
            // swap L and R
             T = L;
            L = R;
            R = T;
        }
       // cout<<L<<" "<<R<<endl;
       ans = solve(L,R,type); // calculate answer for current query
        A = B;     // updating key A
        B = ans;   // updating key B
       printf("%d\n",ans);
    }

}



int main()
{
    frmlty
    {
        cin>>s;

        //scanf("%s",&s);
        N=s.length();


       int n=N;
        loop(i,0,n+1)
        {
            loop(j,0,26)
            dp[j][i]=0;
        }

        loop(i,1,n+1)
        {
            loop(j,0,26)
            {
                dp[j][i]=dp[j][i-1];
            }
            dp[s[i-1]-97][i]++;

        }

        decode();

        }


}




