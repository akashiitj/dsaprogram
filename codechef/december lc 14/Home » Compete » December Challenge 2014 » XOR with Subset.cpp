/* this is diretional dp approch
for i = 1 to N:
    for j = 0 to 1023:
        dp[i][j] = dp[i - 1][j] | dp[i - 1][j ^ a[i]]

        */
#include<bits/stdc++.h>
using namespace std;
int a[1024]= {0};
void intialize()
{
    for(int i=0; i<1024; i++)
        a[i]=0;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int ar[n];
        for(int i=0; i<n; i++)
        {
            cin>>ar[i];
            a[ar[i]]=1;
        }
        sort(ar,ar+n);
        for(int i=0; i<n; i++)
        {

            for(int j=0; j<ar[i]; j++)
                if(a[j]==1) a[ar[i]^j]=1;
        }
        int max1=k;


        for(int j=0; j<1024; j++)
        {

            if(a[j]==1)
            {
                int y=k^j;
             //   cout<<max1<<" "<<y<<endl;
                if(y>max1)
                {
                    max1= k^j;
                    // cout<<j<<" "<<""<<max1<<endl;
                }
            }
        }
        intialize();
        cout<<max1<<endl;
    }
    return 0;
}
