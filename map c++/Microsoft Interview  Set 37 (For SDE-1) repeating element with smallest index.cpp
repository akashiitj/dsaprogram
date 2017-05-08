#include<bits/stdc++.h>
using namespace std;
struct pair1
{
    int i;
    int c;
};
void display (map <int ,pair1> grades,int ml)

{  pair1 p;

    cout << "\tTotal size: " << grades.size() << endl; /* Output the size */

    /* Create an iterator, much like vector iterators */

    map <int ,pair1>::iterator it;
int min1=ml;
    for (it = grades.begin(); it != grades.end(); ++it)
{


        cout  << it->first << setw(10);
        p=it->second;
        cout<<p.c<<" "<<p.i<<endl;
      if(p.c==2&& p.i<min1)
       min1=p.i;

}

    cout << endl; /* Print a new line */
cout<<min1;
}
int f(int a[],int ml)
{   map<int,pair1> map1;
    pair1 p={-1,0},p1;
    map <int,pair1>::iterator it;

    for(int i=0;i<ml;i++)
    {   p.i=-1;
        p.c=0;
        int x=a[i];
        map1[x]=p;
    }
     for(int i=0;i<ml;i++)
    {
        int x=a[i];
        p=map1[x];
        if(p.i==-1)p.i=i;
        p.c=p.c+1;
        map1[x]=p;
    }
    display(map1,ml);

}
main()
{
    int a[6]={2,45,6,2,7,7};
    f(a,6);
}
