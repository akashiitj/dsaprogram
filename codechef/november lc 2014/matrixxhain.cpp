#include <bits/stdc++.h>
using namespace std;
//#define double long long
struct matrix {
    double array[2][2];
};
typedef struct matrix matrix;
#define mod 1000000007
matrix mul(matrix A,matrix B)
{
    matrix C;
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            double sum=0;
            for(int k=0; k<2; k++) {
                sum=sum+A.array[i][k]*B.array[k][j];
            }
            C.array[i][j]=sum;
        }
    }
    return C;
}
matrix Identity;
void initialize()
{
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++)if(i!=j)Identity.array[i][j]=0;
            else Identity.array[i][j]=1;
    }
}
matrix fast_mul(matrix A,int pow)
{
    matrix C;

    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++)if(i!=j)C.array[i][j]=0;
            else C.array[i][j]=1;
    }
    while(pow>0) {
        if(pow&1) {
            C=mul(C,A);
        }
        A=mul(A,A);
        pow>>=1;
    }
    return C;
}
void print(matrix C){
    for(int i=0;i<2;i++,cout<<endl){
        for(int j=0;j<2;j++,cout<<"\t"){
            cout<<C.array[i][j];
        }
    }
}
int main()
{
    int t,n,k;
    //cin>>t;
    string s;
    getline(cin,s);
    cout<<s<<s.length()<<endl;
    matrix c;
    while(t--)
    {
        cin>>k;
         for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cin>>c.array[i][j];
        }}
        c=fast_mul(c,k);
        print(c);
    }


    /*while(Tst--) {
        double N;
        cin>>N;
        if(N==2) {
            cout<<3<<endl;
        }else if(N==3){
            cout<<4<<endl;
        } else  {
            N=N-3;
            //N=N-3;
            matrix C;
            C.array[0][1]=C.array[1][1]=C.array[1][2]=C.array[2][0]=C.array[2][2]=0;
            C.array[0][0]=C.array[0][2]=C.array[1][0]=C.array[2][1]=1;
            matrix result=fast_mul(C,N);
            //print(result);
            cout<<(4*result.array[0][0]+3*result.array[0][1]+2*result.array[0][2])%mod<<endl;
        }
    }*/
    return 0;
}
