#include <iostream>
#include <string.h>
using namespace std;
int c1;
int c;
/*char* function1(char* d)
    {   char *c=d;
        c++;
        c[2]='q';
        return d;
    }
    */
//char*
int sdr(char *s1)//passing string
{
    c1=0;
    int cq=0;
    char *ts=s1,*s=s1;//ts holds required string
    while(s[0]!='\0')//traversing a string
    {
        int i=0;
        c=0;
        if(s[i]==s[i+1])
        {
            c=c+2;
            cq=cq+2;
            while(s[i+c]==s[i])
            {
                c++;
                cq++;
            }
            s=s+c;
        }
        else
        {
            ts[c1]=s[i];
            c1++;
            s++;
        }
    }
    ts[c1]='\0';
    //cout<<cq<<endl;
    return cq;//cheking any duplicate left
}

main()
{
    //  cout<<"enter string";string stri;
    // cin>>stri;
    char str[]="acbbcddc";


    //  char *sp=s;
    //char *d=
    while( sdr(str)!=0);//it may be pass by value
    cout<<str<<endl;
    //sdr(str);
    //cout<<str;
    char str1[] = "geeksforgeeg";
    while( sdr(str1)!=0);
    cout <<str1 << endl;

    char str2[] = "azxxxzy";
    while( sdr(str2)!=0);
    cout << str2 << endl;

    char str3[] = "caaabbbaac";
    while( sdr(str3)!=0);
    cout << str3 << endl;

    char str4[] = "gghhg";
    while( sdr(str4)!=0);
    cout << str4 << endl;

    char str5[] = "aaaacddddcappp";
    while( sdr(str5)!=0);
    cout <<str5 << endl;

    char str6[] = "aaaaaaaaaa";

    while( sdr(str6)!=0);
    cout << str6 << endl;

    char str7[] = "qpaaaaadaaaaadprq";
    while( sdr(str7)!=0);
    cout << str7 << endl;

    char str8[] = "acaaabbbacdddd";
    while( sdr(str8)!=0);
    cout <<str8 << endl;

    char str9[] = "acbbcddc";
    while( sdr(str9)!=0);
    cout << str9 << endl;

    return 0;
}

