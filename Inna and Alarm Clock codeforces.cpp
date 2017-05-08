#include<iostream>
//#include<stdio.h>
using namespace std;

main()
{   int n;
    int sum1=0,sum2=0;

    cin>>n;
     int r[101],c[101];
        int rn,cn;

        for(int i=0;i<101;i++)
        {
            r[i]=0;
            c[i]=0;
        }
    while(n>0)
    {

        cin>>rn;
        cin>>cn;
        r[rn]=1;
        c[cn]=1;
        n--;
    }
     for(int i=0;i<101;i++)
        {
            sum1=sum1+r[i];
             sum2=sum2+c[i];



        }
        if(sum1>=sum2)
            cout<<sum2<<endl;
        else
        cout<<sum1<<endl;
}
