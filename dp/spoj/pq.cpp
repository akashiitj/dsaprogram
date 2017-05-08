#include<bits/stdc++.h>
using namespace std;

int A[1000]= { 0, 46, 46, 0, 2, 47};
//1, 24, 45, 0, 0, 24, 18, 29, 27, 11, 0, 0, 40, 12, 4, 0, 0, 0, 49, 42, 13, 5, 12, 45, 10, 0, 29, 11, 22, 15, 17, 41, 34, 23, 11, 35, 0, 18, 47, 0, 38, 37, 3, 37, 0, 43, 50, 0, 25, 12, 0, 38, 28, 37, 5, 4, 12, 23, 31, 9, 26, 19, 11, 21, 0, 0, 40, 18, 44, 0, 0, 0, 0, 30, 26, 37, 0, 26, 39, 10, 1, 0, 0, 3, 50, 46, 1, 38, 38, 7, 6, 38, 27, 7, 25, 30, 0, 0, 36, 37, 6, 39, 40, 32, 41, 12, 3, 44, 44, 39, 2, 26, 40, 36, 35, 21, 14, 41, 48
//, 50, 21, 0, 0, 23, 49, 21, 11, 27, 40, 47, 49};

int Solution() {
    int n=6;

    int dp[n];
    dp[n-1]=INT_MAX;
    dp[0]=0;
    //memset(dp,,sizeof dp);
    dp[0]=0;
    priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > mi;//min priority q

    mi.push(make_pair(0,A[0]));
    pair<int,int> p;
    for(int i=1;i<n;i++)
    {

        while(mi.top().second<i)
        {
            mi.pop();
        }
        if(mi.size()==0)
        break;

        p=mi.top();
        dp[i]=p.first+1;
        if(i+A[i]>p.second)
        mi.push(make_pair(dp[i],i+A[i]));


    }

    if(dp[n-1]==INT_MAX)
    return -1;
    return dp[n-1];
}


int main() {

	cout<<Solution();
	return 0;
}
