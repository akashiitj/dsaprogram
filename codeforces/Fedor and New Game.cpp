#include<bits/stdc++.h>
using namespace std;
int countSetBits(int n)
{
    unsigned int count = 0;
    while (n)
    {
      n &= (n-1) ;
      count++;
    }
    return count;
}
main()
{
    int n,m,k,sum=0;
    cin>>n>>m>>k;
    int a[m];
    for(int i=0;i<=m;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        if(countSetBits(a[i]^a[m])<=k)sum++;
    }
    cout<<sum<<endl;

}
