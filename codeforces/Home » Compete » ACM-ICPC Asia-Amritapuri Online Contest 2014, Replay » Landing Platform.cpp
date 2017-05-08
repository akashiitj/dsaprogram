#include<bits/stdc++.h>
using namespace std;
main()
{
   double m,n,i,j,c,sum=0,as=0,x=0;
   int i1,j1,i2,j2;
   int m1,n1;
   cin>>m1>>n1;
    m=m1;n=n1;
    double a[m1][n1];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        cin>>a[i][j];
    for(c=0;c<(int)m/2;c++)
    {   sum=0;
    cout<<c<<endl;
        for(i=(0.5)+c;i<m-1;i++)
        {
            for(j=(0.5)+c;j<n-1;j++)
            {   cout<<i<<" "<<j<<endl;sum=0;
            int cd=c;
                i1=i-.5;
                i2=i+.5;
                j1=j-.5;
                j2=j+.5;
                while(cd>=0)

                {  cout<<"jh"<<endl;
                   cout<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<endl;
                    sum=sum+a[i1][j1]+a[i1][j2]+a[i2][j2]+a[i2][j1];
                 cd--;
                 i1=i1-1;
                 i2=i2+1;
                 j1=j1-1;
                 j2=j2+1;
                 cout<<sum<<endl;
                 cout<<x<<"x"<<endl;
                 x++;
                // if(x>10) {cout<<as<<endl;return 0;}
                }

                if(as<sum)as=sum;
            }
        }
    }
    cout<<as<<endl;
}
