#include<bits/stdc++.h>
#include <iomanip>
using namespace std;
double f(double n)
{
   double fact=1.0;
    for(double i=n ; i>=1 ; i--)
fact = fact*i;
return fact;
}
int main()
{

    string s1,s2;
    cin>>s1;
    cin>>s2;
   double c1=0.0,c2=0.0,cqm=0.0,x=0.0,l=0.0,ans=1.0;
    for(double i=0;i<s1.length();i++)
    {
        if(s1[i]=='+')c1++;
        else if(s1[i]=='-')c1--;
        if(s2[i]=='+')c2++;
        else if(s2[i]=='-')c2--;
        else if(s2[i]=='?')cqm++;

    }
    x=abs(c1-c2);
        l=cqm-x;


        if(cqm==0&&x==0)
        {   ans=1.0;
         //  cout << setprecision(9);
            cout<<ans;
            return 0;
        }
        if(l<0||((int)l%2)!=0)
             {   ans=0;
            cout<<ans;
            return 0;
        }
        ans=f(cqm)/(f(l/2)*f(cqm-(l/2)));

        cout<<ans/pow(2,cqm)<<endl;
        return 0;
}
