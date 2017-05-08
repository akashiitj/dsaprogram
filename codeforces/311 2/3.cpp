#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef struct node
{
    ll int l,d;//length & energy required to remove
} node;
node a[100010];
ll int h[210],h2[210];//count numberof legs having cost i
list<ll int> l[100010];//contain list of cost of i length leg
ll int b[100010];//count number of i length leg
int main()
{
    memset(h,0,sizeof(h));
    ll int n;
    scanf("%lld",&n);
    ll int i,j;
    for(i=0; i<n; i++)
    {
        scanf("%lld",&(a[i].l));
        b[i]=0; //Initialise
    }
    for(i=0; i<n; i++)
    {
        scanf("%lld",&(a[i].d));
    }
    for(i=0; i<n; i++)
    {
        l[a[i].l].push_back(a[i].d);
        b[a[i].l]++; //Kind of hash -how many legs to length 'l' available
        h[a[i].d]++;
    }
    ll int ans=LONG_LONG_MAX,temp=0,temp2=0,x,r;
    for(i=100001; i>0; i--)
    {
        if(b[i]==0)
        {
            continue;
        }
        else
        {
            for(j=1; j<210; j++)
            {
                h2[j]=h[j];
            }
            if(b[i]>=((n/2)+1))
            {
                ans=min(ans,temp);
            }
            else
            {
                x=(2*b[i])-1;//for stability with maxlength i total legs must be x
                r=n-x;//to remove
                temp2=temp;
                list<ll int>::iterator it;
                //Removing the maximum leg--check for some other possibility
                for(it=l[i].begin(); it!=l[i].end(); it++)
                {
                    h[*it]--;//removing max length leg
                    h2[*it]--;
                    temp+=*it;

                }
                for(j=1; j<210; j++)//removing r legs
                {
                    if(h2[j]>=r)
                    {
                        temp2+=r*j;
                        break;
                    }
                    else
                    {
                        temp2+=h2[j]*j;
                        r-=h2[j];
                    }
                }
                ans=min(ans,temp2);
                //~ cout<<"Length "<<i<<" b[i] "<<b[i]<<" remove "<<r<<" Energy "<<temp2<<endl;
                n-=b[i];
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
