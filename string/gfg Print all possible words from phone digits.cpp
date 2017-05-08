#include <iostream>
using namespace std;
void print(string s[],int no[],char so[],int i,int e)//i= start point e = end pt
{
  if(i==e)
  {
      for(int j=0;j<s[no[e]].size();j++)
      {
          so[e]=s[no[e]][j];
          cout<<so[0]<<so[1]<<so[2]<<endl;
      }
  }
  else
  {
      for(int q=0;q<s[no[i]].size();q++)
      {so[i]=s[no[i]][q];
      print( s, no, so, i+1, e);
      }
}
}
void printresult (int no[],int ml)
{
 string s[10]={"", "", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};
 char so[ml];//show output
 print( s, no, so, 0, ml-1);
}
int main()
{
   int no[3]={2,3,4};
   printresult(no,3);
   return 0;
}
