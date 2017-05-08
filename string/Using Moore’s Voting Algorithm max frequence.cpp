#include<bits/stdc++.h>
using namespace std;
int findCandidate(int a[], int size)
{
    int maj_index = 0, count = 1;
    int i;
    for(i = 1; i < size; i++)
    {
        if(a[maj_index] == a[i])
            count++;
        else
            count--;
        if(count == 0)
        {
            maj_index = i;
            count = 1;
        }
    }
    return a[maj_index];
}
 main()
 {
     int a[7]={2,2,3,5,6,7,8};
     cout<<findCandidate(a,7);
 }
