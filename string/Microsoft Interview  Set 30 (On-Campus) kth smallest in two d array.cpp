#include<iostream>
#include<vector>
using namespace std;
struct noch
{
    int key;
     int x,y;
};
class heapuv
{
public:
    void swap1(vector<noch>&a,int i,int j)
    {
        int t=a[i].key;
        int ti=a[i].x;
        int tj=a[i].y;
        a[i].key=a[j].key;
        a[i].x=a[j].x;
        a[i].y=a[j].y;
        a[j].x=ti;
        a[j].y=tj;
        a[j].key=t;
    }
    void insert1(vector<noch>&a,int data,int x,int y)//vector<int>a if this is used vectoe is get passed by value
    {
        noch no;
        no.key=data;
        no.x=x;
         no.y=y;
        a.push_back(no);
        int t=a.size();
        //  cout<<t<<endl;
        while(t>=2)
        {
            if(a[(t/2)-1].key>a[t-1].key)
            {
                swap1(a,t-1,(t/2)-1);
                t=t/2;
            }
            else break;
        }
    }
   void heapify(vector<noch>&a,int n)
    {
        int i=n;int ml=a.size();
        while(i<=(a.size()/2))
        {
            if(a[(2*i)-1].key<a[i-1].key&&(2*i)==ml)
            {
                swap1(a,(2*i)-1,i-1);
                i=2*i;
            }
            else if(a[(2*i)-1].key<a[i-1].key&&a[(2*i)-1].key<=a[2*i].key)
            {
                swap1(a,(2*i)-1,i-1);
                i=2*i;
            }

            else if(a[(2*i)].key<a[i-1].key&&a[(2*i)-1].key>=a[2*i].key&&(2*i)!=ml)//remember last condition
            {
                swap1(a,(2*i),i-1);
                i=2*i+1;
            }
            else break;
        }
    }
    void deletemax(vector<noch>&a)
    {
      //  cout<<a[0].key<<endl;
        swap1( a, 0,a.size()-1);
      //  cout<<"swap1"<<endl;
        a.erase(a.begin()+a.size()-1);
       // cout<<"er"<<endl;
        heapify(a,1);
    }
};
main()
{
    vector<noch>heap1;int ni,nj;
    heapuv ho;
    int a[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {25, 32, 37, 48},
                    {29, 33, 39, 50},
                  };
   for(int i=0;i<4;i++)
    ho.insert1(heap1,a[0][i],0,i);


   for(int i=0;i<4;i++)
   {
       ni=heap1[0].x+1;
       nj=heap1[0].y;
       // cout<<i<<endl;
     for(int i=0; i<heap1.size(); i++)
        cout<<heap1[i].key<<"  ";
        cout<<endl;
       ho.deletemax(heap1);
        //cout<<i<<endl;
     for(int i=0; i<heap1.size(); i++)
        cout<<heap1[i].key<<"  ";
        cout<<endl;


       ho.insert1(heap1,a[ni][nj],ni,nj);
       //cout<<i<<endl;
   }
   cout<<heap1[1].key<<endl;

}

