#include<iostream>
#include<math.h>
using namespace std;
class prime
{ public:
    bool check(int x)
    {
        if(x%2==0)return false;
        else
        {
            for(int i=3;i<=sqrt(x);i=i+2)
                if(x%i==0)return false;
        }
        return true;
    }
};
main()
{
    prime po;
    cout<<po.check(18);
}
