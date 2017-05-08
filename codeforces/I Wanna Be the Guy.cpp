#include<bits/stdc++.h>
using namespace std;
main()
{
    int v,i=0,j=0,n;
    cin>>n;
    int p;
    cin>>p;
    int a[p+1];
    a[p]=109;
    for(int i=0; i<p; i++)
        cin>>a[i];
    sort(a,a+p);
    cin>>p;
    int b[p+1];
    b[p]=109;
    for(int i=0; i<p; i++)
        cin>>b[i];
    sort(b,b+p);
    int pre=0;
    int cur=min(a[0],b[0]);
    if(cur==a[0])i++;
    else j++;
    while(cur-pre<=1)
    {
        pre=cur;
        if(a[i]>b[j])
        {
            cur=b[j];
            j++;
        }
        else
        {
            cur=a[i];
            i++;
        }
    }
    if(pre==n)
        cout<<"I become the guy."<<endl;
    else cout<<"Oh, my keyboard!"<<endl;

}
