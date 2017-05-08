#include<bits/stdc++.h>
using namespace std;
void f(int a1[],int a2[],int a3[],int l1,int l2,int l3)
{
    int i=0,j=0,k=0;
    while(i<l1&&j<l2&&k<l3)
    {
        if(a1[i]==a2[j]&&a2[j]==a3[k])
        {
            cout<<a1[i]<<endl;
            i++;j++;k++;
        }
        else if(a1[i]<a2[j]&&a2[j]<=a3[k])
        {
            i++;
        }
         else if(a2[j]<a1[i]&&a1[i]<=a3[k])
        {
            j++;
        }
         else
        {
            k++;
        }
    }
}
int main()
{
    int ar1[] = {1, 5, 10, 20, 40, 80};
    int ar2[] = {6, 7, 20, 80, 100};
    int ar3[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    int n3 = sizeof(ar3)/sizeof(ar3[0]);

    cout << "Common Elements are ";
    f(ar1, ar2, ar3, n1, n2, n3);
    return 0;
}
