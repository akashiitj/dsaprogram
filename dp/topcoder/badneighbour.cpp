#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i = a; i < b; i++)

int a[100]={ 0,94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,
  6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
  52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 };
int dp1[100];
int dp2[100];

int f(int i)
{
    if(dp1[i]!=-1)return dp1[i];
    if(i==0)return 0;
    if(i==1)return a[i];
    dp1[i]= max(f(i-1),f(i-2)+a[i]);
    return dp1[i];
}

int f1(int i)
{
    if(dp2[i]!=-1)return dp2[i];
    if(i==0)return 0;
    if(i==1)return a[i+1];
    dp2[i]= max(f1(i-1),f1(i-2)+a[i+1]);
    return dp2[i];
}


main()
{
    int n;
    cin>>n;
    loop(i,0,n+1)
    {
        dp1[i]=-1;
        dp2[i]=-1;
    }
    dp1[0]=0;
    dp2[0]=0;
    cout<<max(f(n-1),f1(n))<<endl;

}


/*#include<bits/stdc++.h>
using namespace std;
class BadNeighbors
{
public:
    int maxDonations(vector<int> donations)
    {
        int n = donations.size();

        int dp[n];//including first element
        int dp2[n];
        dp[0]=0;
        dp[1]=donations[0];
        for(int i=2; i<n; i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+donations[i-1]);
        }

        dp2[0]=0;
        dp2[1]=donations[1];
        for(int i=2; i<n; i++)
        {
            dp2[i]=max(dp2[i-1],dp2[i-2]+donations[i]);
        }
        return max(dp[n-1],dp2[n-1]);
    }
};



int main()
{
    int n;
    cin>>n;
    vector<int>  a;
    for(int i=0; i<n; i++)
        a.push_back(i);
    BadNeighbors b;
    cout<<b.maxDonations(a)<<endl;
    return 0;
}

*/
/*

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class BadNeighbors{
   public:
  int maxDonations(int donations[])
{
    int n = sizeof(donations) / sizeof(int) ;

    int dp[n];//including first element
    int dp2[n];
    dp[0]=0;
    dp[1]=donations[0];
    for(int i=2;i<n;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+donations[i-1]);
    }

    dp2[0]=0;
    dp2[1]=donations[1];
    for(int i=2;i<n;i++)
    {
        dp2[i]=max(dp2[i-1],dp2[i-2]+donations[i]);
    }
    return max(dp[n-1],dp2[n-1]);
}

   }



};


int main(){
    int a[]={10, 3, 2,4};
    BadNeighbors *bd = new BadNeighbors();
    cout<<bd->maxDonations(a);
}

*/
