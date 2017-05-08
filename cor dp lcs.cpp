#include <iostream>
using namespace std;
void printTable(int** c, int rows, int columns){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout<< c[i][j]<<"  ";
        }    cout<<endl;
    }
}
void printlcs(int **b,string x,int m,int n)
{
    if (m==0||n==0)return;
     if (b[m][n]==1)
    {
         printlcs(b, x, m-1, n-1);
           cout<<x[m-1];
    }
    else if(b[m][n]==0)
         printlcs(b, x, m-1, n);
    else printlcs(b,x,m,n-1);

}

class lsp//longest subsquence problem
 { public:
     void maxlength(string s1,string s2,int *c)
     {
         int m=s1.size();
         int n=s2.size();
         for (int i=0;i<=n;i++)
         c[i]=0;
         for (int i=1;i<=m;i++)
         c[i*(n+1)]=0;
         for(int i=1;i<=m;i++)
         {
             for(int j=1;j<=n;j++)
             {
                 if(s1[i-1]==s2[j-1])
                 {
                     c[i*(n+1)+j]=  c[i-1*(n+1)+j-1]+1;


                 }
                 else if ( c[i-1*(n+1)+j]>=  c[i*(n+1)+j-1])
                 {
                      c[i*(n+1)+j]= c[i-1*(n+1)+j];
                 }
                 else
                 {
                      c[i*(n+1)+j]= c[i*(n+1)+j-1];
                 }

             }

         }
    }

    void maxlength1(string s1,string s2)
    {
         int m=s1.size();
         int n=s2.size();

         int** c = new int*[m+1];
    for(int i = 0; i < m+1; i++) {
        c[i] = new int[n+1];
        c[i][0]=0;
    }
        for(int j = 0; j < n+1; j++){ c[0][j]=0; }
         int** b = new int*[m+1];
    for(int i = 0; i < m+1; i++) {
        b[i] = new int[n+1];

    }
        //for(int j = 0; j < n+1; j++){ c[0][j]=0; }
         for(int i=1;i<=m;i++)
         {
             for(int j=1;j<=n;j++)
             {
                 if(s1[i-1]==s2[j-1])
                 {
                    c[i][j]=c[i-1][j-1]+1;

                    b[i][j]=1;
                 }
                 else if ( c[i-1][j]>=  c[i][j-1])
                 {
                      c[i][j]= c[i-1][j];
                      b[i][j]=0;
                 }
                 else
                 {
                      c[i][j]= c[i][j-1];
                      b[i][j]=66;
                 }
                 }

             }


          printTable(c,m+1,n+1);
          printTable(b,m+1,n+1);
           printlcs(b, s2, m,n);
     }
};
void arrayprint(int *a,int m,int n)
{for(int i=0;i<m;i++)
         {
             for(int j=0;j<n;j++)
             {
                 cout<<a[i*n+j]<<"  ";
             }
             cout<<endl;

         }
}

 main()
{
      string s1,s2;
      s1="qwerty";
      s2="qwdefrgthyju";
      lsp lo;
      //int c[4][4];
      lo.maxlength1(s1,s2);






}
