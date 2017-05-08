#include<bits/stdc++.h>
using namespace std;
bool f(string a,string b,string c)
{
    int i=0,j=0,k=0;
    while(k<c.length())
    {
        if(a[i]==c[k]&&i<a.length())i++;
        if(b[j]==c[k]&&j<b.length())j++;
        k++;
    }
    if(i==a.length()&&j==b.length())return true;
}

main()
{
    cout<<f("asd","weer","asdwer");
}
