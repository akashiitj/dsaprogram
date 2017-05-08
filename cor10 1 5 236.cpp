#include<iostream>
using namespace std;
int ml, a[12234],c1=0;
int p1=1,p2=1;
class c
{ public:
    void insert1(int x);//insert at front
    void insert2(int x);//insert at end
    void delete1();//delete from front
    void delete2();//delete from end
    int addone(int x);
};
int c::addone(int x)
{
  return((x%ml)+1);
}
void c::insert1(int x)
{
  if(addone(p2)==p1)cout<<"deque1 is full";
  else
  {
      for(int i=p2;i>=0;i--)
        a[i]=a[i-1];
      a[0]=x;
      p2++;
  }
}

void c::insert2(int x)
{
    if(p2<(ml))
        {a[p2-1]=x;p2++;}
}
void c::delete1()
{
    if(p1==p2)cout <<"it is empty";
    else p1++;
}
void c::delete2()
{
    if(p1==p2)cout <<"it is empty";
    else p2--;
}
main()
{
    cout<<"enter maxlength";
    cin>>ml;
    c co;
    string s;
  while(true)
    {
        cin>>s;
        if(s[0]=='i'&&s[6]=='1')
        {
            int e;
            cin>>e;
            co.insert1(e);
        }
        if(s[0]=='i'&&s[6]=='2')
        {
            int e;
            cin>>e;
            co.insert2(e);
        }
        if(s[0]=='d'&&s[6]=='1')
            co.delete1();
        if(s[0]=='d'&&s[6]=='2')
            co.delete2();
        if (s[0]=='s')
        {
            for(int i=p1-1;i<p2-1;i++)cout<<a[i]<<"   ";
        }
        if(s[0]=='e'&&s[1]=='x')break;
    }

}
