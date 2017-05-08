#include<iostream>
#include<vector>
using namespace std;
class heapuv
{   public:
    void swap1(vector<int>&a,int i,int j)
    {
        int t=a[i-1];
        a[i-1]=a[j-1];
        a[j-1]=t;
    }
    void insert1(vector<int>&a,int data)//vector<int>a if this is used vectoe is get passed by value
    {   a.push_back(data);
     int t=a.size();
      //  cout<<t<<endl;
        while(t>=2)
        { if(a[(t/2)-1]<a[t-1])
          {
              swap1(a,t,t/2);
              t=t/2;
          }
          else break;

        }
    }
};
main()
{
    vector<int>heap1;
    heapuv ho;
     ho.insert1(heap1,11);
    ho.insert1(heap1,16);

    //cout<<heap1.size()<<endl;
    for(int i=0;i<heap1.size();i++)
        cout<<heap1[i]<<"  ";

}
