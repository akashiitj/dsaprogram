#include <iostream>

using namespace std;
void printTable(int** table, int rows, int columns){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
             cout<<table[i][j]<<"  ";
        }    cout<<endl;
    }
}
class asp
{   public:
    void aspudp(int s[],int f[],int los)//length of s
    {
      int** c = new int*[los];
      for(int i = 0; i < los; i++)
      {
        c[i] = new int[los];
        for(int j = 0; j < los; j++){ c[i][j] = 0; }
      }
      int ** table=new int *[los];
     int rows=los;
      int columns=los;
      for(int i = 0; i < rows; i++) {
        table[i] = new int[columns];
        for(int j = 0; j < columns; j++){ table[i][j] = -1; }// sample set value;
                                     }
      for(int l=1;l<=los-1;l++)
      {
        for(int i=0;i<los-l;i++)
        {
          int j=i+l;
          if(f[i]<s[j])
          {
            for(int k=i+1;k<j;k++)
            {   if(s[k]>=f[i]&&f[k]<=s[j])
            {
                int flag=c[i][k]+c[k][j]+1;
                if(flag>c[i][j])
                {
                    c[i][j]=flag;
                    table[i][j]=k;
                }
            }
            }
          }
        }
      }
    printTable(c,  rows,  columns);
    }
    void aspugar(int s[],int f[],int n)//n is actual length
    {
        int i=1,j=2;
        while(i<n&&j<n+1)
        {
          if(s[j-1]>=f[i-1])
          {//cout<<"dd";
              cout<<j<<"  ";
          i=j;
          j++;
          }
          else j++;
        }

    }

};
int main()
{
   //cout << "Hello World" << endl;
   int s[5]={0,2,1,4,100000};//start time of 3 avtivity
   int f[5]={0,3,5,10,100000};//finish time of all 3 activity
   asp ao;
  // ao.aspudp(s,f,5);
   ao.aspugar(s,f,5);
   return 0;
}
