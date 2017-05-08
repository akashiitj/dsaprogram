#include<iostream>
using namespace std;
class string1
{public:
    void removal(char *p)
    {   int i=0;
        char *tt=p,*ts=p;//we store string in ts and traverse through string with help of tt.
        while(tt[0]!='\0')
        {  // cout<<"tt "<<tt[0]<<endl;
            if(tt[0]=='b')
             {
      //          cout<<"hhhhhhh"<<endl;
                //ts[i]=tt[0];
             //    cout<<"ts "<<ts[i]<<endl;
                //i++;
                tt++;

             }
             else if(tt[0]=='a'&&tt[1]=='c')tt=tt+2;
             else {

                ts[i]=tt[0];
                i++;
                tt++;
             }
        }
        //cout<<tt<<endl;
        //cout<<ts<<endl;
    ts[i]='\0';
    }
};
main()
{
    string1 so;
    char str[]="bbaccbac";
    so.removal(str);
    cout<<str<<endl;
    char str1[] = "ad";
    so.removal(str1);
    cout << str1 << endl;

    char str2[] = "acbac";
    so.removal(str2);
    cout << str2 << endl;

    char str3[] = "aaac";
    so.removal(str3);
    cout << str3 << endl;

    char str4[] = "react";
    so.removal(str4);
    cout << str4 << endl;

    char str5[] = "aa";
    so.removal(str5);
    cout << str5 << endl;

    char str6[] = "ababaac";
    so.removal(str6);
    cout << str6 << endl;

}
