#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define ull unsigned long long
#define ll long long
struct cell
{
    ll i;
    ll j;

};
ull pow2(ull x)
{   ull x1=1;
    if(x==0)return 1;
    while(x--)
    x1=x1*2;
    return x1;

}

ll getMid(ll s, ll e) {  return s + (e -s)/2;  }


ull getSumUtil(ll *st, ll ss, ll se, ll qs, ll qe, ll index)
{

    if (qs <= ss && qe >= se)
        return (ull)st[index];


    if (se < qs || ss > qe)
        return 0;


    ll mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*index+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*index+2);
}


void updateValueUtil(ll *st, ll ss, ll se, ll i, ll diff, ll index)
{

    if (i < ss || i > se)
        return;


    st[index] = st[index] + diff;
    if (se != ss)
    {
        ll mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*index + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*index + 2);
    }
}


void updateValue(ll arr[], ll *st, ll n, ll i, ll new_val)
{

    if (i < 0 || i > n-1)
    {
        printf("Invalid Input");
        return;
    }


    ll diff = new_val - arr[i];


    arr[i] = new_val;


    updateValueUtil(st, 0, n-1, i, diff, 0);
}


ull getSum(ll *st, ll n, ll qs, ll qe)
{

    if (qs < 0 || qe > n-1 || qs > qe)
    {

        return -1;
    }

    return getSumUtil(st, 0, n-1, qs, qe, 0);
}


ll constructSTUtil(ll arr[], ll ss, ll se, ll *st, ll si)
{

    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }


    ll mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}


ll *constructST(ll arr[], ll n)
{

    ll x = (ll)(ceil(log2(n)));
    ll max_size = 2*(ll)pow2( x) - 1;

    long long *st=(long long *) malloc( max_size * sizeof(long long) );

    constructSTUtil(arr, 0, n-1, st, 0);


    return st;
}


int main()
{   ll n,i,i1;
    scanf("%lld",&n);
    ll arr[n],x,y;
    ll sum[n+1];
    //ll sumd[n+1];

    sum[0]=0;

    for( i=0;i<n;i++)
       scanf("%lld",&arr[i]);
    struct cell cs[n];
     ll *st = constructST(arr, n);
    for( i1=0;i1<n;i1++)
    {
        scanf("%lld%lld",&x,&y);
        cs[i1].i=x;
        cs[i1].j=y;
      //  sum[i1]=getSum(st,n,x-1,y-1);
      sum[i1+1]=sum[i1]+getSum(st,n,x-1,y-1);
    //  sund[i1+1]=sum[i1+1];
      //  printf(" %llu\n",sum[i1]);
    }

    ll *fst = constructST(sum, n);
    // printf(" %llu\n",getSum(fst,n,1,2));

    ll q;
    ll qt;
    ll d;
     scanf(" %lld",&q);
     while(q--)
     {
          scanf("%lld",&qt);
          if(qt==1)
          {   scanf("%lld%lld",&x,&y);
              updateValue(arr, st, n, x-1, y);
              for( i1=0;i1<n;i1++)
              {

                 sum[i1+1]=sum[i1]+getSum(st,n,cs[i1].i-1,cs[i1].j-1);

                /*  if(x>=cs[i1].i&&x<=cs[i1].j)
                  { //  printf(" %llu  %lld\n",getSum(st,n,cs[i1].i-1,cs[i1].j-1),i1);
                     sum[i1+1]=sum[i1]+getSum(st,n,x-1,y-1);
                     // updateValue(sum, fst, n, i1,getSum(st,n,cs[i1].i-1,cs[i1].j-1) );
                  }
*/              }
          }
          else if(qt==2){
            scanf("%lld%lld",&x,&y);
            printf(" %llu\n",sum[y]-sum[x-1]);
           // printf(" %llu\n",getSum(fst,n,x-1,y-1));

          }
     }


    return 0;
}
