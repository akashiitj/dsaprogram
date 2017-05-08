#include<iostream>
#include<string>
using namespace std;

// A utility function to print a substring str[low..high]
void printSubStr( char* str, int low, int high )
{
    for( int i = low; i <= high; ++i )
        cout<<str[i];
}

// This function prints the longest palindrome substring of str[].
// It also returns the length of the longest palindrome
int longestPalSubstr( char *s )
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
    }
    printSubStr( s, start,  start+maxlength-1 );
   return maxlength; // return length of LPS
}

// Driver program to test above functions
int main()
{
    char str[] = "forgeeksskeegfor";
    cout<<longestPalSubstr(str);
    return 0;
}
