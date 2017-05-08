#include<stdio.h>
#include<math.h>
#define inf 1000000000
struct node
{
    double cost;
    double area;
};
struct coupon
{
    double arr[16];
};
struct coupon arr1[32768];
struct node dp[32768][17];
int main(void)
{
    int i,j,k,l,n,m,p,r;
    double a,b,c,d,q;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        double pa[n][2];
        int power[16];
        power[0]=1;
        for(i=1; i<=15; i++)
            power[i]=power[i-1]*2;
        k=power[n];
        for(i=0; i<=k-1; i++)
        {
            for(j=1; j<=n; j++)
                arr1[i].arr[j]=1;
        }
        for(i=0; i<=n-1; i++)
        {
            scanf("%d%d",&p,&r);
            pa[i][0]=p;
            pa[i][1]=r;
            scanf("%d",&j);
            for(l=0; l<=j-1; l++)
            {
                scanf("%d%d",&p,&r);
                q=r;
                q=q/100;
                q=1-q;
                m=power[i];
                arr1[m].arr[p]*=q;
            }
        }
        for(i=1; i<=k-1; i++)
        {
            j=log(i)/log(2);
//cout<<j<<endl;
            j=power[j];
            l=i-j;
            for(m=1; m<=n; m++)
                arr1[i].arr[m]=arr1[j].arr[m]*arr1[l].arr[m];
        }
        for(i=1; i<=n+1; i++)
        {
            dp[0][i].cost=0;
            dp[0][i].area=0;
        }
        for(i=1; i<=k-1; i++)
        {
            d=inf;
            a=inf;
            b=1;
            for(j=1; j<=n; j++)
            {
                l=power[j-1];
                if((i|l)==i)
                {
                    m=i-l;
                    dp[i][j].cost=dp[m][n+1].cost+(pa[j-1][0]*arr1[m].arr[j]);
                    dp[i][j].area=dp[m][n+1].area+pa[j-1][1];
                    c=dp[i][j].cost/dp[i][j].area;
                    if(c<d)
                    {
                        d=c;
                        a=dp[i][j].cost;
                        b=dp[i][j].area;
                    }
                }
                else
                {
                    dp[i][j].cost=inf;
                    dp[i][j].area=1;
                }
            }
            dp[i][n+1].cost=a;
            dp[i][n+1].area=b;
        }
        a=inf;
        for(i=1; i<=k-1; i++)
        {
            b=dp[i][n+1].cost/dp[i][n+1].area;
            if(b<a)
                a=b;
        }
        printf("%0.4lf\n",a);
    }
    return 0;
}

