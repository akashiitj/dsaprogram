#include<bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for(int i=a;i<b;i++)


int prnt[1000];
int obnumberofroot(int obn)//pass objectnumber of object whose root we have to fing
{   int i=obn;
    while(prnt[obn]!=obn)obn=prnt[obn];
    //obn is now root object no
    while(i!=obn)//doing path compressing
    {
        int j=prnt[i];
        prnt[i]=obn;
        i=j;
    }
    return obn;
}
int find(int i,int j)
{
    return (obnumberofroot(i)==obnumberofroot(j));
}
void unionbyobnumber(int i,int j)
{
    int x=obnumberofroot( i);
    int y=obnumberofroot( j);
    //now all those object whose pindex is y we make it x
    prnt[y]=x;
}
int main()
{
    int n;
    cout<<"enter no of objects"<<endl;
    cin>>n;

    loop(i,0,n)
    {
        prnt[i]=i;
        // if you want to give obnumber you cn give
    }
    cout<<find(0,1)<<"\n";
    unionbyobnumber(0,1);
    unionbyobnumber(1,2);
    //unionbyobnumber(2,0);
    cout<<find(0,2)<<endl;
    cout<<obnumberofroot(0);

    return 0;
}


