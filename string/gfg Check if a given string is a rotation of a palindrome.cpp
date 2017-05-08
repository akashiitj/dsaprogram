#include<iostream>
#include <algorithm>
#include<string>
using namespace std;

string rotateu(string s,int i)
{
    rotate(s.begin(), s.begin()+i, s.end());
    return s;
}

bool isPalindrome(string str)
{
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = str.length() - 1;

    // Keep comparing characters while they are same
    while (h > l)
        if (str[l++] != str[h--])
            return false;

    // If we reach here, then all characters were matching
    return true;
}
//here first apporch had ended

void printSubStr( char* str, int low, int high )
{
    for( int i = low; i <= high; ++i )
        cout<<str[i];
}

// This function prints the longest palindrome substring of str[].
// It also returns the length of the longest palindrome
int longestPalSubstr( char *s,int ol )
{
    int n=strlen(s);
    int start=0,maxlength=1;
    bool a[n][n];
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++)
        a[i][i]=1;
    for(int l=2;l<=n;l++)
    {
        for(int i=0;i<=n-l;i++)
        {
            if(l==2 && s[i]==s[i+1])
            {
                 a[i][i+1]=1;
                 start=i;
                 maxlength=l;
            }
            else
            {
                int j=i+l-1;
                if(a[i+1][j-1]==1 &&s[i]==s[j])
                {
                    a[i][j]=1;
                    start=i;
                    maxlength=l;
                }

            }
        }
        if(maxlength==ol)goto qw;
    }
    qw:
    printSubStr( s, start,  start+maxlength-1 );
    cout<<endl;
   return maxlength; // return length of LPS
}

class frq//for req q by another method try to recall it
{
public:
bool ispal(char *s)
   {
    int l=strlen(s);
    string s1=s;
    s1=s1.append(s);
    cout<<s1<<endl;
    s=&s1[0];
    if(l==longestPalSubstr( s, l ))return true;
    else false;
   }
};
main()
{
    string s="abcd";
    /*for(int i=1;i<s.size();i++)
    {
         s=rotateu(s,1);
        cout<<s<<endl;
        if(isPalindrome(s))
        {
            cout<<"yes";
            break;
        }
    }*/
    frq fo;
    cout<<fo.ispal(&s[0]);

}
