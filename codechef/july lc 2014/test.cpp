#include <bits/stdc++.h>
using namespace std;
void f(char a1[],char a2[],int l1,int l2)
{
  int i;
    char a3[l2];
    sort(a2,a2+l2);
    for( i=1;i<=l1-l2+1;i++)
    {
      copy(a1+i-1,a1+i-1+l2,a3);
      a3[l2]='\0';
      //cout<<a3<<endl;
      sort(a3,a3+l2);
//cout<<a3<<endl;
     if (strcmp(a2, a3) == 0)
        cout<<i<<endl;
    }


}
 main ()
{
  char a1[]="BACDGABCDA";
  char a2[]="ABCD";
 // cout<<strlen(a2);
  //sort(a2,a2+3);
  f(a1,a2,strlen(a1),strlen(a2));
}
