#include<bits/stdc++.h>
using namespace std;
long long a[30];
long long f(long long nn,long long flag)//function to return color of node
{   long long c=1;
    for(long long i=0;i<30;i++)
    {
        if(nn<=a[i])
        {
            if(c%2==1&&flag==0)return 0;
            if(c%2==1&&flag==1)return 1;
            if(c%2==0&&flag==0)return 1;
            if(c%2==0&&flag==1)return 0;
        }
        c++;
    }
}
main()
{   ios_base::sync_with_stdio(false);
    long long x=2,y;
    for(long long i=0;i<30;i++)
    {
        a[i]=x-1;
       x= x<<1;
    }
    int q,flag=0,c1,c2,cb=0,cr=0;
    cin>>q;
    string s;
    while(q--)
    {
        cin>>s;
        if(s=="Qi")
        {
            flag=(flag+1)%2;
        }
        if(s=="Qb")
        {   cb=0;
            cin>>x>>y;
            c1=f(x,flag);
            c2=f(y,flag);
            if(c1==0)cb++;
                if(c2==0)cb++;
            while(x!=y)
            {

                if(x>y)
                {
                    x=x/2;
                    c1=(c1+1)%2;
                    if(c1==0&&x!=y)cb++;
                }
                else if(x<y)
                {
                    y=y/2;
                    c2=(c2+1)%2;
                    if(c2==0&&x!=y)cb++;

                }
            }
            cout<<cb<<endl;
        }
        if(s=="Qr")
        {   cr=0;
            cin>>x>>y;
            c1=f(x,flag);
            c2=f(y,flag);
            if(c1==1)cr++;
                if(c2==1)cr++;
            while(x!=y)
            {

                if(x>y)
                {
                    x=x/2;
                    c1=(c1+1)%2;
                    if(c1==1&&x!=y)cr++;
                }
                else if(x<y)
                {
                    y=y/2;
                    c2=(c2+1)%2;
                    if(c2==1&&x!=y)cr++;

                }
            }
            cout<<cr<<endl;
        }
    }

}
