#include <iostream>
#include<vector>
using namespace std;
class rsa
{
public:
    int modulo(int a,int b,int c)
    {
        long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
        while(b > 0)
        {
            if(b%2 == 1)
            {
                x=(x*y)%c;
            }
            y = (y*y)%c; // squaring the base
            b /= 2;
        }
        return x%c;
    }
    int inverse(int a,int p)
    {
        int aq=p;
        vector< vector<int> > vI2Matrix;    // Declare two dimensional array
        vector<int> A(2,0);
        while(p%a!=0)
        {
            A[0]=p/a;
            A[1]=p%a;
            p=a;
            a=A[1];
            vI2Matrix.push_back(A);
        }
        cout<<vI2Matrix.size();
        for(int i=0; i<vI2Matrix.size(); i++)
        {
            for(int j=0; j<2; j++)
                cout<<vI2Matrix[i][j]<<" ";
            cout<<endl;
        }

        int t1=-1*vI2Matrix[vI2Matrix.size()-1][0],t2=1;
        for(int i=vI2Matrix.size()-2; i>=0; i--)
        {
            int dv=t1;
            t1=((t1)*(-1*vI2Matrix[i][0]))+t2;
            t2=dv;

        }
        while(t1<=0)
            t1=t1+aq;
        return t1;
    }
    int gcd(int a,int b)
    {
        if(a%b==0)return b;
        else return gcd(b,a%b);
    }
    int returnnumbercoprimetonumber(int z)
    {
        if(z%2==0)
            for(int i=3; i<z; i=i+2)
            {
                if(gcd(z,i)==1)cout<<i<<"  ";
            }
        else
        {
            for(int i=2; i<z; i=i++)
            {
                if(gcd(z,i)==1) cout<<i<<"  ";
            }

        }
    }
    void ftps(int n)//function to print stroing
    {
        cout<<(char)((n/100)+65)<<(char)((n%100)+65);
    }

    void encryption(string s,int p,int q,int e)
    {
        int seckey=inverse(e,(p-1)*(q-1));

        for(int i=0; i<s.length(); i=i+2)
        {
            int x,x1,x2=0;
            x1=(int)s[i]-64;
            if(s[i+1]!='\0')   x2=(int)s[i+1]-64;
         //   else x2=(int)s[i+1]-65;
            x=(100*x1)+x2;
            cout<<"original  message "<<s[i];
            if(s[i+1]!='\0') cout<<s[i+1];
            cout<< "  with associated no. "<<x<<endl;
            cout<<"corresponding encrypted message ";
            ftps(modulo(x,e,p*q));
            cout<<"  with associated no. "<<modulo(x,e,p*q)<<" ";//e
           // ftps(modulo(x,e,p*q));
            cout<<endl;
            cout<<"decrypted  message "<<s[i]<<s[i+1]<< "  "<<"  with associated no. "<<modulo(modulo(x, e,p*q),seckey,p*q)<<endl;
        }

    }

};
main()
{   cout<<"this program is for words that contain small and capital letter "<<endl;
    cout<< "you have to enter p and q such that their product is greater than 5858"<<endl;
   cout<< "enter p and q two prime no according to mentioned instruction"<<endl;
       rsa ro;
    int p,q,e;
    cin>>p>>q;
    cout<<endl;
    a:
    cout<<"enter value of e such that its gcd with p-1 * q-1 is 1"<<endl;
    cin>>e;
    if(ro.gcd(e,((p-1)*(q-1)))!=1)
    {
        cout<<"you have entered wrong value of key try another"<<endl;
        goto a;
    }
    string s;

    cout<<"enter string  ";
    cin>>s;
    //ro.  returnnumbercoprimetonumber((p-1)*(q-1));
    ro.  encryption(s,p,q,e);
}
