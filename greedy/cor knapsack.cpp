#include <iostream>

using namespace std;
int dpa[100][100]={-1};
class knapsack
{  public:
    int maxvurec(int w[],int v[],int maxw,int n)
    {   if (n == 0 || maxw == 0)
       return 0;
        if(dpa[maxw][n]!=-1)return dpa[maxw][n];
        if(w[n-1]>maxw)
        {
            return maxvurec(w,v,maxw,n-1);
        }
        else
        {  int val=max(maxvurec(w,v,maxw,n-1),v[n-1]+maxvurec(w,v,maxw-w[n-1],n-1));
             dpa[maxw][n]=val;
            return  val;
        }

    }
};

int main()
{
   for(int i = 0; i < 100; i++) {

        for(int j = 0; j < 100; j++){ dpa[i][j] = -1; }// sample set value;
    }cout<<dpa[23][90];
   cout << "Hello World" << endl;
    int knapsackSize = 10;
    int w[4] = {5,4,6,3};
    int v[4] = {10,40,30,50};
   knapsack ko;
   cout<<ko.maxvurec(w,v,10,4);
   return 0;
}
