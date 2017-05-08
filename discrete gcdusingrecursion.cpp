#include<iostream>
using namespace std;
class disrete
{
 public:
     int gcd(int a,int b)
     {
         if(a%b==0)return b;
         else return gcd(b,a%b);
     }

};
main()
{
    int a,b;
    disrete do3;
    cout<<"enter two number";
    cin>>a;
    cin>>b;
    cout<<"there gcd is "<<do3.gcd(a,b);
}
