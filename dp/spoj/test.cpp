#include<bits/stdc++.h>
using namespace std;
struct dist
{
    int feet;
};
void add(int a,int b, int* c)

{
    *c=a+b;
}

void adds( dist dist1,dist dist2, dist *dist3)
{
    (*dist3).feet=dist1.feet+dist2.feet;
}
int main()
{
    int a=5;
    int b=6;
    int c;
    add(a,b,&c);
    cout<<c<<endl;
    struct dist dist1,dist2,dist3;
    dist1.feet=5;
    dist2.feet=4;
    adds(dist1,dist2,&dist3);
    cout<<dist3.feet<<endl;

}
