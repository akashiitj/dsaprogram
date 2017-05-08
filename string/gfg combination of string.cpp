#include <iostream>

using namespace std;
class gfgstringcombination
{ public:
    void swap (char s[],int  x, int  y)
  {
    char temp;
    temp = s[x];
    s[x]= s[y];
    s[y] = temp;
  }
  void swapt (char x, char y)
{
    char temp;
    temp = x;
    x = y;
    y = temp;
}
  void permute(char s[],int sia,int fia)//starting index of array,
  {
      if(sia ==fia)cout<<s[0]<<s[1]<<s[2];
      else
      {
          for(int i=sia;i<=fia;i++)
          {  //swapt(s[sia],s[fia])//see nothing is going to happen here because you are passing character not character array
              swap (s,sia,i);
              permute(s,sia+1,fia);
               swap (s,i,sia);
               cout<<endl;
          }
      }
  }
};

int main()
{
   cout << "Hello World" << endl;
   gfgstringcombination go;
   char s[]="abc";
   go.permute(s,0,2);
   return 0;
}
