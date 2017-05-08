#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        long long sns[n];
        long long sum=0,x;
        for(int i=0; i<n; i++)
        {
            cin>>sns[i];
            sum=sum+sns[i];
        }
        sort(sns,sns+n);

        if(sum%k==0)
        {
            x=sum/k;
            bool flag;
            for(int i=n-1; i>n-1-k; i--)//this loop will cal for first k large elements
            {
                flag=false;
                int temp[i];
                copy(sns,sns+i,temp);
                int pow_set_size = pow(2, i);
                int counter, j;
                long long val,s=0;
                val=x-sns[i];
                if(s==val)
                {
                    flag=true;
                    continue;
                }
                for(counter = 0; counter < pow_set_size; counter++)
                {
                    queue<long long> q;
                    for(j = 0; j < i; j++)
                    {
                        if(counter & (1<<j))
                        {
                            s= s + temp[j];
                            q.push(j);
                        }
                    }
                    if(s==val)
                    {
                        s=0;
                        flag=true;
                        while(!q.empty())
                        {
                            sns[q.front()]=0;
                            q.pop();
                        }
                        break;
                    }
                    else s=0;
                }
                if(!flag)
                {
                    cout<<"no"<<"\n";
                    break;
                }
                else continue;
            }
            if(flag)cout<<"yes"<<"\n";
        }
        else cout<<"no"<<"\n";
    }


}

