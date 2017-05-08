#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,b) for(int i=a;i<b;i++)

int nof[5000001]={0};
int cs[5000001];
void seive()
{  cs[0]=0;
    loop(i,2,5000001)
    {
       //cout<<nof[i]<<endl;
        if(nof[i]==0)
        {   nof[i]=1;
            for(int j=i+i;j<=5000000;j=j+i)
            nof[j]=i;
        }
        else   nof[i]=nof[i/nof[i]]+1;
        cs[i]=cs[i-1]+nof[i];

    }
}

main()
{
    int t,a,b;
    seive();
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&a,&b);

        printf("%d\n",cs[a]-cs[b]);
    }
}
