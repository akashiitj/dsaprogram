#include<bits/stdc++.h>
using namespace std;
main(){
set<pair<int ,int> > sn;
int n,x,y;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>x>>y;
    sn.insert(make_pair(x,y));

}
pair<int,int> p;
p=make_pair(1,1);
//sn.erase(p);
cout<<sn.count(p)<<endl;
set<pair<int ,int> >::iterator i;
for(i=sn.begin();i!=sn.end();i++)
{
    cout<<i->first<<" "<<i->second;
}

}
