#include<iostream>
using namespace std;
  void swap1(int **a,int i,int j)
    {
        int *t;
        t=a[i];
        a[i]=a[j];
        a[j]=t;
    }

 void heapify(int **a,int n,int ml)
    {
        int i=n;
        while(i<=(ml/2))
        {
            if(*a[(2*i)-1]<*a[i-1]&&(2*i)==ml)
            {
                swap1(a,(2*i)-1,i-1);
                i=2*i;
            }
            else if(*a[(2*i)-1]<*a[i-1]&&*a[(2*i)-1]<=*a[2*i])
            {
                swap1(a,(2*i)-1,i-1);
                i=2*i;
            }

            else if(*a[(2*i)]<*a[i-1]&&*a[(2*i)-1]>=*a[2*i]&&(2*i)!=ml)//remember last condition
            {
                swap1(a,(2*i),i-1);
                i=2*i+1;
            }
            else break;
        }
    }
    void heapformation(int **a,int ml)
    {

        for(int i=(ml/2); i>=1; i--)
            heapify(a,i,ml);
    }
    main()
{
    cout<<"enter no of sorted array";
    int k,n;

    cin>>k;
    cout<<"enter no of element sorted in each array";
    cin>>n;
    int ar[k][n];int *hp[k];
    for(int i=0;i<k;i++)
    {   hp[i]=ar[i];
        for(int j=0;j<n;j++)
            cin>>ar[i][j];
    }
    heapformation(ar,k);
    for(int i=0; i<k; i++)
        cout<<*ar[i]<<"   ";



}
