#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
bool areAnagram(char *s1,char *s2,int ml)
{
    int c[256]={0};
for(int i=0;i<ml;i++)
{
    c[s1[i]]++;
    c[s2[i]]--;
}
for(int i=0;i<256;i++)
if(c[i]!=0)return false;

return true;

}




int main()
{
    char str1[] = "geeksforgeekue";
    char str2[] = "forgeeksgeeks";
 cout<<(int)str1[0]<<endl;
    if(strlen(str1)!=strlen(str2))
    {
    printf("The two strings are not anagram of each other");
    return 0;
    }
    if ( areAnagram(str1, str2,strlen(str1)) )
      printf("The two strings are anagram of each other");
    else
      printf("The two strings are not anagram of each other");

    return 0;
}
