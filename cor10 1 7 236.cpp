#include<iostream>
using namespace std;
int ml;
class cq
{
public:
    int f=1,r=1,q[155555];
    int addone(int no)
    {
        return((no%ml)+1);
    }
    int isempty()
    {
        if(f==r)return true;
        else return false;
    }
    int isfull()
    {
        if (addone(r)==f)return true;
        else false;
    }
    void enqueue(int elem)
    {
        if(isfull())cout<<"queue is full";
        else
        {
            q[r-1]=elem;
            r=addone(r);
            cout<<q[r-2]<<endl;
        }
    }
    int dequeue()
    {
        if(isempty())cout<<"queue is empty";
        else {f=addone(f);return q[f-2];}
    }
};
main()
{
    string s;
    cout<<"enter max length";
    cin>>ml;
    cq cq1,cq2,swap1;
    while(true)
    {
        cin>>s;
        if(s[0]=='p'&&s[1]=='u')
        {
            int e;
            cin>>e;
            cq1.enqueue(e);
        }
        if(s[0]=='p'&&s[1]=='o')
        {
            for(int i1=0;i1<cq1.r-2;i1++)
            {
                cq2.enqueue(cq1.dequeue());
            }
            cq1.dequeue();
            swap1=cq1;
            cq1=cq2;
            cq2=swap1;
        }
        if(s[0]=='s')
        {
            for(int i2=cq1.f-1;i2<cq1.r-1;i2++)cout<<cq1.q[i2]<<"    ";
            cout<<endl<<"let see";
            for(int i2=cq2.f-1;i2<cq2.r-1;i2++)cout<<cq2.q[i2]<<"    ";cout<<endl;
        }
        if(s[0]=='e'&&s[1]=='x')break;
    }


}
