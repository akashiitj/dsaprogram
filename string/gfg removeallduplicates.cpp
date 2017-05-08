#include<iostream>
using namespace std;
string f(string s)
{
    int i=0,j=0;//i where next is inserted,j next element to be examined
    int a[256]={0};
    while(j<s.length())
    {
        if(a[s[j]]==0)
        {   //cout<<a[s[i]]<<endl;
            a[s[i]]=1;
           // cout<<s[i]<<" "<<s[j]<<endl;
            s[i]=s[j];
            j++;
            i++;
        }
        else j++;
    }
 // cout<<s<<endl;
 s.resize(i);
    return s;
}
main()
{
    cout<<f("geeksforgeeks");

}
