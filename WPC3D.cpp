#include<iostream>
# include <math.h>
using namespace std;
bool check(int qw)
{
    for(int i=2; i<=sqrt(qw); i++)
    {
        if(qw%i==0) return false;
    }
    return true;
}
int f(int n)
{
    int no=n;
    int sum=0,count1=0;
    if(n%2 == 0)
    {
        sum=sum+2;
        count1++;
    }
    while (n%2 == 0)
    {
        n = n/2;
    }


    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        if(n%i == 0)
        {
            sum=sum+i;
            count1++;
        }
        while (n%i == 0)
        {
            n = n/i;
        }
    }
    if (n > 2)
    {
        sum=sum+n;
        count1++;
    }
    // cout<<sum<<"   "<<count1;
    if(check(no))return 1;
    else return (f(sum)+count1);
    //cout<<sum<<"   "<<count1;
}
main()
{
    int tc;
    cin>>tc;
    while(tc>0)
    {
        int nqq;
        cin>>nqq;
        // if(nqq==4)cout<<"2"<<endl;
        cout<<f(nqq)<<endl;
        tc--;
    }
}
