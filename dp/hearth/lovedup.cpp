#include <iostream>
#include <vector>
#define inf 100000000000000000
#define int long long
using namespace std;

main()
{
    vector<int> a[17];
    int dp[131072]= {0};
    int d[17],l[17];
    int power[18]= {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072};
    int n;
    cin>>n;
    int lim=power[n];
    for(int i=1; i<lim; i++)
    {
        int temp=i;
        int p=0;
        while(temp!=0)
        {
            if(temp%2)
                p++;
            temp=temp/2;
        }
        a[p-1].push_back(i);
    }
    for(int i=0; i<n; i++)
        cin>>l[i];
    for(int i=0; i<n; i++)
    {
        cin>>d[i];
        d[i]=i*d[i];
    }
    for(int i=0; i<n; i++)
    {
        int val1=i*(i+1)/2;
        int val2=(n-i-1)*i;
        for(int j=0; j<a[i].size(); j++)
        {
            dp[a[i][j]]=-inf;
            int temp=a[i][j];
            int c=0;
            while(temp!=0)
            {
                if(temp%2)
                    dp[a[i][j]]=max(dp[a[i][j]],dp[a[i][j]-power[c]]+n*l[c]-(val1+val2)*d[c]);
                c++;
                temp=temp/2;
            }
        }
    }
    cout<<dp[power[n]-1]<<"\n";
    return 0;
}

