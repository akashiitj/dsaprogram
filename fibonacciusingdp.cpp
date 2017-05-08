#include<iostream>
using namespace std;

int fib(int n)
{

    if(n==0||n==1)return 1;
    if(dp[n]!=0)return dp[n];
    dp[n]=fib(n-1)+fib(n-2);
//    c++;
return dp[n];
}

main(){
    int n;
    cin>>n;
   static int dp[n]; dp[n]={0};
    cout<<fib(n);
}
