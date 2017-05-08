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
            cout<<r;
        }
    }
    void dequeue()
    {
        if(isempty())cout<<"queue is empty";
        else f=addone(f);
    }
};
main()
{
    string s;
    cout<<"enter max length";
    cin>>ml;
    cq cqo;
    while(true)
    {
        cin>>s;
        if(s[0]=='e'&&s[1]=='n')
        {
            int e;
            cin>>e;
            cqo.enqueue(e);
        }
        if(s[0]=='d'&&s[1]=='e')
            cqo.dequeue();
        if(s[0]=='e'&&s[1]=='x')break;
    }


}
