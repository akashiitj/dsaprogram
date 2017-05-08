#include<iostream>
#include<string>
using namespace std;
main()
{
    string s="dddsw",s3="aaa";
   // char *cp=&s[3];
   // cout<<cp<<endl;
   // s[3]='o';
    //s.append(s.begin()+2,)
   //  s.append("dots are cool",5);
    s.resize(2);
    s.append(s3,1,2);
        cout<<s<<endl;
}
