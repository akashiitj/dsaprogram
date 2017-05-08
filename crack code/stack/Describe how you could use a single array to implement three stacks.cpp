#include<iostream>
using namespace std;
class s3
{
    int *a;
    int t1,b1,t2,t3;
public:
     s3(int n)
    {
        a=new int[n];
        t1=-1;
        b1=n/3;
        t2=b1-1;
        t3=n;
    }
    void push1(int x)
    {  cout<<t1<"  "<<b1<<"  "<<t2<<"  "<<t3<<endl;
        if(t1<b1-1)
        {
            t1++;
            a[t1]=x;
        }
        else cout<<"stack overflow1"<<endl;
    }
    void push2(int x)
    {   cout<<t1<<"  "<<b1<<"  "<<t2<<"  "<<t3<<endl;
        if(t2<t3-1)
        {
            t2++;
            a[t2]=x;
        }
        else cout<<"stack overflow2"<<endl;
    }
    void push3(int x)
    {   cout<<t1<<"  "<<b1<<"  "<<t2<<"  "<<t3<<endl;
        if(t2<t3-1)
        {
            t3--;
            a[t3]=x;
        }
        else cout<<"stack overflow3"<<endl;
    }
    void show(int n)
    {
         for(int i=0;i<=t1;i++)
        cout<<a[i]<<" ";
        cout<<endl;
         for(int i=b1;i<=t2;i++)
         cout<<a[i]<<" ";
         cout<<endl;
         for(int i=n-1;i>=t3;i--)
         cout<<a[i]<<" ";
        cout<<endl;
    }
};
main()
{   int n;
cout<<!3<<endl;
    cin>>n;
    s3 so(n);
    so.push1(1);
    so.push2(11);
    so.push3(12);
    so.push3(133);
    so.push2(13);
    so.push1(14);
    so.show(n);
}
