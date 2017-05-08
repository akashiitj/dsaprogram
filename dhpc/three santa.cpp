#include<iostream>
using namespace std;
#define LL unsigned long long


int main()
{
    ios_base::sync_with_stdio(false);

    LL santa=1;
    LL banta=2;
    LL ganta=6;
    LL sum=9;
    int t;
    cin>>t;
    LL n;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        if(n==1)
        {
            cout<<sum<<endl;
        }
        else
        {
            LL m=1;
            while(m<n)
            {
                santa=2*(banta%(1000000000+7)+ganta%(1000000000+7))%(1000000000+7);
                banta=2*(santa%(1000000000+7)+ganta%(1000000000+7))%(1000000000+7);
                ganta=2*(santa%(1000000000+7)+banta%(1000000000+7))%(1000000000+7);
                m++;
            }
            sum=(santa%(1000000000+7)+banta%(1000000000+7)+ganta%(1000000000+7))%(1000000000+7);
            cout<<sum<<endl;
            santa=1;
            banta=2;
            ganta=6;
            }
    }
    return(0);

}
