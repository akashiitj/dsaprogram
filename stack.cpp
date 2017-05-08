#include<iostream>
using namespace std;
int top=-1;
int x;
int a[10000];

class stack1
{
public:
    int isempty();
    int isfull();
    void push(int y);
    void pop();
};
int stack1::isempty()
{
    if(top==(-1))return true;
    else return false;
}
int stack1::isfull()
{
    if(top==x-1)return true;
    else return false;
}
void stack1::push(int y)
{
    if(isfull())cout<<"stack is full";
    else
    {
        a[top+1]=y;
        top++;
    }
    //  cout<<top<<"  "<<x;
}
void stack1::pop()
{
    if(isempty())cout<<"stack is empty";
    else top--;
}
main()
{

    cout<<"enter size of stack";
    cin>>x;
    //array1 ao;
    //ao.createarray(x);
    while(true)
    {   cout<<"enter push number for push and pop for poping and exit for terminatining process"<<endl;
        stack1 so;
        string s;
        cin>>s;
        if (s[0]=='p'&&s[1]=='u')
        {
            int q;
            cin>> q;
            so.push(q);
        }
        if (s[0]=='p'&&s[1]=='o')
        {
            so.pop();
        }
        if(top>=0)for(int j=0; j<=top; j++)cout<<a[j]<<"  ";
        if(s[0]=='e')break;
    }
}
