#include<bits/stdc++.h>
using namespace std;

// A utility function to get max of two integers
int max (int x, int y) { return (x > y)? x : y; }
int L[3000][3000]={0};
// Returns the length of the longest palindromic subsequence in seq
int lps(string str)
{
   int n = str.length();
   int i, j, cl;
   //int L[n][n];  // Create a table to store results of subproblems


   // Strings of length 1 are palindrome of lentgh 1
   for (i = 0; i < n; i++)
      L[i][i] = 1;


    for (cl=2; cl<=n; cl++)
    {
        for (i=0; i<n-cl+1; i++)
        {
            j = i+cl-1;
            if (str[i] == str[j] && cl == 2)
               L[i][j] = 2;
            else if (str[i] == str[j])
               L[i][j] = L[i+1][j-1] + 2;
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }

    return L[0][n-1];
}

/* Driver program to test above functions */
int main()
{
    string seq;
    cin>>seq;
    int n = seq.length();
    lps(seq);
    long long max=-1;
    for(int i=0;i<n-1;i++)
        if(L[0][i]*L[i+1][n-1]>max)max=L[0][i]*L[i+1][n-1];
    cout<<max<<endl;
    return 0;
}
