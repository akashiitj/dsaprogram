#include<bits/stdc++.h>
using namespace std;
unsigned long long hcf(unsigned long long x,unsigned long long y) //function definition
{
    if (y!=0)
        return hcf(y,x%y);
    else
        return x;
}

int  main()
{
    unsigned long long l,r;
    cin>>l>>r;
    for(unsigned long long i=l; i<r-1; i++)
    {
        for(unsigned long long j=l+1; j<r; j++)
        {
            if(hcf(i,j)==1)
            {
                for(unsigned long long k=j+1; k<=r; k++)
                {
                    if(hcf(j,k)==1)
                    {
                        if(hcf(i,k)!=1)
                        {cout<<i<<" "<<j<<" "<<k<<endl;
                          return 0;}
                          }
                }
            }
        }
    }
    cout<<"-1"<<endl;
}
