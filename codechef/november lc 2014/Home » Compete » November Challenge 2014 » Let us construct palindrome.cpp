#include<bits/stdc++.h>
using namespace std;
int ispalindrome(string s,int i,int j)
{
    while(i<j)
    {
        if(s[i]!=s[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}
main()
{
    ios_base::sync_with_stdio(false);
    int t,c=0;
    string a;
    cin>>t;
    int i,j;
    while(t--)
    {
        cin>>a;
        c=0;
        i=0;
        j=a.length()-1;
        if(j==1||ispalindrome(a,i,j)==1)cout<<"YES"<<endl;
        else
        {
            while(i<j)
            {
                if(a[i]==a[j])
                {
                    i++;
                    j--;
                }
                else
                {
                    if(ispalindrome(a,i,j-1)==1||ispalindrome(a,i+1,j)==1)
                        cout<<"YES"<<endl;
                    else
                        cout<<"NO"<<endl;
                        break;
                }

            }


        }
    }






}

