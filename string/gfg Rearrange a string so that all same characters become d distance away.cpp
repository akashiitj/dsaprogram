#include<iostream>
#include<vector>
using namespace std;

struct cf//cfa character frequency array
{
    int f;
    char c;
};
cf cfa[58]= {{0,0}};
struct noch
{
    int key;
    char str;//first string lene pe passing
};
class rf
{
public:
    void ftscwf(string s)//function to store character with frequency
    {
        int m=0;
        for(int i=0; i<s.size(); i++)
        {
            if(cfa[(int)s[i]-65].f==0)m++;
            cfa[(int)s[i]-65].f++;
            cfa[(int)s[i]-65].c=s[i];
        }
        cout<<m<<endl;
    }
    void swap1(vector<noch>&a,int i,int j)
    {
        int t=a[i].key;
        char ts=a[i].str;
        a[i].key=a[j].key;
        a[i].str=a[j].str;
        a[j].str=ts;
        a[j].key=t;
    }
    void insert1(vector<noch>&a,int data,char s)//vector<int>a if this is used vectoe is get passed by value
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
        int i=n;
        int ml=a.size();
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
    void isaih(vector<noch>&a,cf sa[])//insert structure array into heap
    {
        for(int i=0; i<58; i++)
        {
            char sa1=sa[i].c;
            if(sa[i].f!=0)
                insert1(a,sa[i].f,sa1);
        }
    }
    void restr(string s,int d)//required function to convert string
    {

    }

};
main()
{

    string str;
    vector<noch>heap1;
    cout<<"enter a string";
    cin>>str;
    rf rfo;
    rfo.ftscwf(str);
    for(int i=0; i<58; i++)
        cout<<cfa[i].f<<"  "<<cfa[i].c<<endl;
    rfo.isaih(heap1,cfa);
    for(int i=0; i<heap1.size(); i++)
        cout<<heap1[i].key<<"  "<<heap1[i].str<<endl;
    int j=0;
     for(int i=0; i<heap1.size(); i++)
     {   char c=heap1[i].str,int f=heap1[i].key;
         if(str[j]=='\0');
         {  for(int k=j;k<f;k=k+d)
            str[k]=c;


         }
     }

}
