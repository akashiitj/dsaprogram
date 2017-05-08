#include<bits/stdc++.h>
using namespace std;
int iscomposite(int x)
{
    if (x%2==0)
        return 1;
    else{

        for(int i=3;i<=sqrt(x);i=i+2)
            if(x%i==0)return 1;

    }
    return 0;
}
int main()
{
    int n;
    cin>>n;
    for(int i=4;i<=n/2;i++)
    {
        if(iscomposite(i)&&iscomposite(n-i))
        {
            cout<<i<<" "<<n-i<<endl;
            return 0;
        }
    }
    return 0;
}
