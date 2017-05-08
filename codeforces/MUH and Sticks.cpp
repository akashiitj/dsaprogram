#include<bits/stdc++.h>
using namespace std;
main()
{
    int a[9]= {0};
    int x1=0,x2=0,x4=0,x5=0,x6=0,x;
    for(int i=0; i<6; i++)
    {
        cin>>x;
        a[x-1]=a[x-1]++;
    }
    x=0;
    for(int i=0; i<9; i++)
    {
        if(a[i]==6)
        {
            x6=1;
        }
        if(a[i]==2)x2++;
        if(a[i]==5)x5++;
        if(a[i]==1)x1++;
        if(a[i]==4)x4++;

    }
        if(x6==1||(x2==1&&x4==1))cout<<"Elephant"<<endl;
    else if((x4==1&&x1==2)||(x5==1&&x1==1))cout<<"Bear"<<endl;
    else cout<<"Alien"<<endl;
}

