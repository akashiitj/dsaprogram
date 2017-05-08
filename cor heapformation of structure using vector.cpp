#include<iostream>
#include<vector>
using namespace std;
struct noch
{
    int key;
    string str;
};
class heapuv
{
public:
    void swap1(vector<noch>&a,int i,int j)
    {
        int t=a[i].key;
        string ts=a[i].str;
        a[i].key=a[j].key;
        a[i].str=a[j].str;
        a[j].str=ts;
        a[j].key=t;
    }
    void insert1(vector<noch>&a,int data,string s)//vector<int>a if this is used vectoe is get passed by value
    {
        noch no;
        no.key=data;
        no.str=s;
        a.push_back(no);
        int t=a.size();
        //  cout<<t<<endl;
        while(t>=2)
        {
            if(a[(t/2)-1].key<a[t-1].key)
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
            if(a[(2*i)-1].key>a[i-1].key&&(2*i)==ml)
            {
                swap1(a,(2*i)-1,i-1);
                i=2*i;
            }
            else if(a[(2*i)-1].key>a[i-1].key&&a[(2*i)-1].key>=a[2*i].key)
            {
                swap1(a,(2*i)-1,i-1);
                i=2*i;
            }

            else if(a[(2*i)].key>a[i-1].key&&a[(2*i)-1].key<=a[2*i].key&&(2*i)!=ml)//remember last condition
            {
                swap1(a,(2*i),i-1);
                i=2*i+1;
            }
            else break;
        }
    }
     void deletemax(vector<noch>&a)
    {
        //cout<<a[0].key<<endl;
        swap1( a, 0,a.size()-1);
        a.erase(a.end());
        heapify(a,1);
    }
};
main()
{
    vector<noch>heap1;
    heapuv ho;
    ho.insert1(heap1,11,"eleven");
    ho.insert1(heap1,16,"qwe");
    ho.insert1(heap1,123,"qwe");
    ho.insert1(heap1,13,"we");
    ho.deletemax(heap1);
    cout<<heap1.size()<<endl;
    for(int i=0; i<heap1.size(); i++)
        cout<<heap1[i].key<<"  "<<heap1[i].str<<endl;

}

