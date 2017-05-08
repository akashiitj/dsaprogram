#include<iostream>
#include<vector>
using namespace std;

    int inverse(int a,int p)
    {  int aq=p;
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
 main()
 {
    cout<<inverse(7,20);
 }
