#include<bits/stdc++.h>
using namespace std;
int mark[1000001];//0 indicate it is prime 1 indicate its not prime
void seive(int sz)
{
    memset(mark,0,sizeof(mark));
    mark[1]=1;
    int sq=sqrt(sz);
    for(int i=2; i<=sq; i++)
    {
        if(mark[i]==0)
        {

            for(int j=i*i; j<=sz; j=j+i)
            {
                mark[j]=1;
            }
        }
    }
    for(int i=2; i<=sz; i++)
        if(mark[i]==0)
            cout<<i<<" ";
}
main()
{
    seive(70);
}
