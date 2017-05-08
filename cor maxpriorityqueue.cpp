#include<iostream>
using namespace std;
class heap
{
public:
    void swap1(int a[],int i,int j)
    {
        int t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
    void heapify(int a[],int n,int ml)
    {
        int i=n;
        while(i<=(ml/2))
        {
            if(a[(2*i)-1]>a[i-1]&&(2*i)==ml)
            {
                swap1(a,(2*i)-1,i-1);
                i=2*i;
            }
            else if(a[(2*i)-1]>a[i-1]&&a[(2*i)-1]>=a[2*i])
            {
                swap1(a,(2*i)-1,i-1);
                i=2*i;
            }

            else if(a[(2*i)]>a[i-1]&&a[(2*i)-1]<=a[2*i]&&(2*i)!=ml)//remember last condition
            {
                swap1(a,(2*i),i-1);
                i=2*i+1;
            }
            else break;
        }
    }

    void heapformation(int a[],int ml)
    {

        for(int i=(ml/2); i>=1; i--)
            heapify(a,i,ml);
    }
    void deletemin(int a[],int i,int ml)
    {
        //cout<<a[0]<<endl;
        swap1( a, i-1,ml-1);
        heapify(a,i,ml-1);
    }
    void increasekey(int a[],int p,int val)
    {
        if(val<a[p])
        {
            cout<<"invalid operation";

        }
        int i=p;
        a[i-1]=val;
        while(i>=1)
        {
            if(a[(i/2)-1]<a[i-1])
            {
                swap1(a,i-1,(i/2)-1);
                i=i/2;
            }
            else break;
        }
    }

};
main()
{
    int ml;

    cout<<"enter size of array";
    cin>>ml;
    int ar[ml];
    for(int i=0; i<ml; i++)
        cin>>ar[i];
    heap ho;

    ho.heapformation(ar,ml);
    for(int i=0; i<ml; i++)
        cout<<ar[i]<<"   ";
    cout<<endl;
    //ho.deletemin(ar,7);
    // ho.sorting(ar,ml);
    //ho.increasekey(ar,2,55);
    //ho.sorting(ar,ml);
    ho.deletemin(ar,1,ml);
    for(int i=0; i<ml; i++)
        cout<<ar[i]<<"   ";
}
