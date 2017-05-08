#include<iostream>
using namespace std;

int x;int i=0;int i1;int c;
class stack1
{
public:


int a[10000];int top=-1;
    int isempty();
    int isfull();
    void push(int y);
    int  pop();
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
    else//
    {
        a[top+1]=y;
        top++;//cout<<top<<endl;
    }
    //  cout<<top<<"  "<<x;
}
int  stack1::pop()
{
    if(isempty() )return 1234;
    else {top--;
    return a[top+1];}
}
main()
{cout<<"enter size of stack";
    cin>>x;
    string s;
    //array1 ao;
    //ao.createarray(x);
    stack1 so1,so2;
   while(true)
    {
        cin>>s;
        if(s[0]=='e'&&s[1]=='n')
        {
            int e;
            cin>>e;
            so1.push(e);
        }
        if(s[0]=='d'&&s[1]=='e')
            {   c=so1.top;
                //cout<<c<<endl;
                while(c>=0)
                {    //cout<<"test"<<so1.pop();
                    so2.push(so1.pop());//cout<<so2.a[i]<<endl;i++;
                    c--;
                }
                   //for(int df=0;df<i;df++)
                  //  cout<<so2.a[df]<<"   ";
                   //cout<<endl;
                cout<<so2.pop();
                c=so2.top;i=0;
                //cout<<c<<endl;
                while(c>=0)
                {
                    so1.push(so2.pop());c--;
                }
           }
      if(s[0]=='s'&&s[1]=='h')
         {
              for(i1=0;i1<=so1.top;i1++)cout<<so1.a[i1]<<"   ";      }
        if(s[0]=='e'&&s[1]=='x')break;
    }
}

