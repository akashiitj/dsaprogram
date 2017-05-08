#include<iostream>
using namespace std;
main()
{
    int no;
    cin>>no;
    while(no>0)
    {
        long long i=0;
        long long l,d,s,c;
        cin>>l>>d>>s>>c;
       // long long a[d];
        for( i=1; i<d; i++)
        {
            s=s+(s*c);
            if(s>=l)break;

        }

        if(s>=l)cout<<"ALIVE AND KICKING"<<endl;
        else cout<<"DEAD AND ROTTING"<<endl;
        no--;
    }
}
