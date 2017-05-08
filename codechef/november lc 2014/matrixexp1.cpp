#include <bits/stdc++.h>
using namespace std;


    double array[26][26];

typedef struct matrix matrix;
 mul(double A[][26],double B[][26])
{
    //matrix C;
    for(int i=0; i<26; i++)
    {
        for(int j=0; j<26; j++)
        {
            double sum=0.0;
            for(int k=0; k<26; k++)
            {
                sum=sum+A.array[i][k]*B.array[k][j];
            }
            C.array[i][j]=sum;
        }
    }
    return C;
}

matrix fast_mul(matrix A,int pow)
{
    matrix C;

    for(int i=0; i<26; i++)
    {
        for(int j=0; j<26; j++)if(i!=j)C.array[i][j]=0.0;
            else C.array[i][j]=1.0;
    }
    while(pow>0)
    {
        if(pow&1)
        {
            C=mul(C,A);
        }
        A=mul(A,A);
        pow>>=1;
    }
    return C;
}
void print(matrix C){
    for(int i=0;i<26;i++,cout<<endl){
        for(int j=0;j<26;j++,cout<<"\t"){
            cout<<C.array[i][j];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int Tst,n,t;
    cin>>Tst;
    set<string> set;

    double pro=0.0,dd;
//cout<<fixed<<setprecision(16)<< pro;
    string s,s1;
    matrix c;
    while(Tst--)
    {
        cin>>n>>t;
        cin>>s;
        for(int i=0; i<26; i++)
        {
            for(int j=0; j<26; j++)
            {
                cin>>dd;
                c.array[i][j]=dd;
            }
        }
        print(c);
        pro=0.0;
        c=fast_mul(c,t);
        cout<<"after"<<endl;
        print(c);
        while(n--)
        {
            cin>>s1;
            if(set.count(s1)==0){
            set.insert(s1);
            if(s.length()==s1.length()&&s.length()==3)pro=pro+(c.array[int(s[0])-97][int(s1[0])-97]*c.array[int(s[1])-97][int(s1[1])-97]*c.array[int(s[2])-97][int(s1[2])-97]);
            else  if(s.length()==s1.length()&&s.length()==2)pro=pro+(c.array[int(s[0])-97][int(s1[0])-97]*c.array[int(s[1])-97][int(s1[1])-97]);
            else  if(s.length()==s1.length()&&s.length()==1)pro=pro+(c.array[int(s[0])-97][int(s1[0])-97]);
            }
        }



        cout<<fixed<<setprecision(16)<<pro<<endl;
    }

    return 0;
}

