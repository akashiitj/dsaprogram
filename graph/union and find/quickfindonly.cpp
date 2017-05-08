//it do only quick find o(1) and union takes o(n)
#include<bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for(int i=a;i<b;i++)
struct object
{
    int pindex;//parent index
    int obnumber;//by default we assume obnumber to be original index no, object number is more appropiate word for obnumber
};
int find(object oa[],int ml,int i,int j)
{
    return (oa[i].pindex==oa[j].pindex);
}
void unionbyobnumber(object oa[],int ml,int i,int j)
{
    int x=oa[i].pindex;
    int y=oa[j].pindex;
    //now all those object whose pindex is y we make it x
    loop(x1,0,ml)
    {
        if(oa[x1].pindex==y)oa[x1].pindex=x;
    }
}
int main()
{
    int n;
    cout<<"enter no of objects"<<endl;
    cin>>n;
    object oa[n];
    loop(i,0,n)
    {
        oa[i].pindex=i;
        // if you want to give obnumber you cn give
    }
    cout<<find(oa,n,0,1);
    unionbyobnumber(oa,n,0,1);
    cout<<find(oa,n,0,1);

    return 0;
}
