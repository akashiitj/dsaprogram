#include<iostream>
using namespace std;
struct st
{
    int visitno;
    int c;//count
};
char f(string s)
{   int x=-1,i;
    st a[256];
    for( i=0;i<256;i++)
    {
       a[i].c=0;
       a[i].visitno=0;

    }
    int visit=1;
    for(i=0;i<s.length();i++)
    {
        if(a[s[i]].c==0)
        {
            a[s[i]].c=1;
            a[s[i]].visitno=visit;
            visit++;
        }
        else
            a[s[i]].c=2;
    }
    visit=1000;
    for(i=0;i<256;i++){
        if(a[i].c==1)

        {
            if(a[i].visitno<visit)
            {
                visit=a[i].visitno;
                x=i;
            }
        }
        }
        if(x==-6)return '\0';
return char(x);
}
main()
{
    cout<<f("scsaa");
}
