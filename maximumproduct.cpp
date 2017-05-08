#include<iostream>
#include<math.h>
using namespace std;
int main ()
{
    unsigned long long int n,m,x=1;
    cin>>n;
    m=n%3;
    n=n/3;
  ////  //cout<<n<<endl<<m<<endl;
    n=n-1;
    for(int i=0;i<n;i++)x=x*3;
    n=(m+3)*x;
    cout<<n;
}
