#include<bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for(int i=a;i<b;i++)
struct object
{
    int pindex;//parent index
    int obnumber;//by default we assume obnumber to be original index no, object number is more appropiate word for obnumber
};
int obnumberofroot(object oa[],int obn)//pass objectnumber of object whose root we have to fing
{
    while(oa[obn].pindex!=obn)obn=oa[obn].pindex;
    return obn;
}
int find(object oa[],int i,int j)
{
    return (obnumberofroot(oa,i)==obnumberofroot( oa,j));
}
void unionbyobnumber(object oa[],int i,int j)
{
    int x=obnumberofroot( oa, i);
    int y=obnumberofroot( oa,j);
    //now all those object whose pindex is y we make it x
    oa[y].pindex=x;
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
    cout<<find(oa,0,1);
    unionbyobnumber(oa,0,5);
    cout<<obnumberofroot(oa,5);

    return 0;
}

