#include<bits/stdc++.h>
using namespace std;
main()
{    int data[5] = { 5, 1, 4, 2, 3 };
    //set<int> sn(data, data+5);
    set<int> sn;
    set<int>::iterator it,it1,it2;
    for(int i=5;i>0;i--)
        sn.insert(i);
    it1= sn.find(4);
    it2=sn.find(2);
    sn.erase(it2,it1);//remember order we can also delete by value and by passinfg single iterator;

    //sn.erase(sn.find(5));
    if(sn.find(5)!=sn.end())
    {
        cout<<"element found";
    }
    for(it=sn.begin();it!=sn.end();it++)
        cout<<*it;

}
