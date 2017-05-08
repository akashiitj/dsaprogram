#include<bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for(int i=a;i<b;i++)
struct object
{
    int pindex;//parent index
    int obnumber;//by default we assume obnumber to be original index no, object number is more appropiate word for obnumber
    int height;
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
    //attaching tree wiyh small height to tree with large height
    int h1=oa[x].height;
    int h2=oa[y].height;
    if(h1>=h2)
    {
        oa[y].pindex=oa[x].pindex;
        if(h1==h2)oa[x].height++;
    }
    else
         oa[x].pindex=oa[y].pindex;

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
        oa[i].height=0;
    }
    cout<<find(oa,0,4);
    unionbyobnumber(oa,0,5);
    unionbyobnumber(oa,3,4);
    unionbyobnumber(oa,0,4);
    cout<<find(oa,0,4)<<endl;
    cout<<oa[0].height<<obnumberofroot(oa,4);
    return 0;
}


