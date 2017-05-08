#include<iostream>
#include<math.h>
using namespace std;
class primefactor
{
public:int c=0;
    void allpf(int x)
    {   if(x%2==0)c++;
        while(x%2==0)
        {x=x/2;
         cout<<2<<" ";
        }
         for (int i = 3; i <= sqrt(x); i = i+2)
    {   if(x%i==0)c++;
        // While i divides n, print i and divide n
        while (x%i == 0)
        {
            cout<<i<<"  ";
            x = x/i;
        }
    }

    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (x > 2)
        {cout<<x<<"  "<<endl;c++;}
        cout<<"total no of primefactor distinct  "<<c;
    }
};
main()
{
    primefactor po;
    po.allpf(63);
}
