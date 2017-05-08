#include<iostream>
#include<algorithm>
using namespace std;
string f(string s)
{
    int j,i;
    for( i=s.length()-1; i>0; i--)
    {
        if(s[i-1]<s[i])
        break;
    }

    i=i-1;
    int x=s[i];
    int y=i+1;

    while(s[y]>x)
    {
        y++;
    }

    swap(s[i],s[y-1]);
    sort(s.begin()+i+1,s.end());
    return s;
}

main()
{
    cout<<f("dcfeba");
}
