#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,b) for(int i=a;i<b;i++)
#define ll long long

ll dp[102][102][51];

ll f(int e1,int e2,int size,int numMoves)
{
    if(e1<0||e1>=size||e2<0||e2>=size)
        return 0;
    if(numMoves<0)return 0;
    if(dp[e1][e2][numMoves]!=-1)return dp[e1][e2][numMoves];
    ll ans1=0,ans2=0;

    loop(dx,-1,2)
    loop(dy,-1,2)
    if(dx!=0||dy!=0)
        ans1=ans1+f(e1+dx,e2+dy,size,numMoves-1);

    loop(dx,-2,3)
    loop(dy,-2,3)
    if (abs(dx) + abs(dy) == 3)
        ans2 += f(e1+dx, e2+dy, size, numMoves-1);

    dp[e1][e2][numMoves]=ans1+ans2;
    return  dp[e1][e2][numMoves];
}

ll howMany(int size, vector<int> start, vector<int> end1, int numMoves)
{
    loop(i,0,size)
    loop(j,0,size)
    loop(k,0,numMoves+1)
    dp[i][j][k]=-1;
    int s1=start[0];
    int s2=start[1];
    int e1=end1[0];
    int e2=end1[1];

    dp[s1][s2][0]=1;

    return f(e1,e2,size,numMoves);
}


main()
{
    vector<int> start= {0,0};
    vector<int> end1= {0,99};
    cout<<howMany( 100,start, end1, 50);


}
