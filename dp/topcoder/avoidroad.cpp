#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,n) for(int i=a;i<n;i++)

#define  ll long long

map<string,int> m;



ll dp[500][500];

ll numWays(int width, int height,vector<string> bad)
{
    // string s3=to_string(width);
    loop(i,0,bad.size())
    {
        m[bad[i]]=1;
    }
    dp[0][0]=1;
    loop(i,0,height+1)
    {
        loop(j,0,width+1)
        {
            if(j-1>=0)
            {

                stringstream convert; // stringstream used for the conversion

                convert<<j;
                // cout<<convert.str()<<" lkl "<<endl;
                convert<<" ";
                convert <<i;
                convert<<" ";
                convert <<j-1;
                convert<<" ";
                convert <<i;
                string s1=convert.str();

                //   cout<<s1<<" s1 "<<endl;



                //  stringstream convert; // stringstream used for the conversion

                stringstream convert1;
                convert1<<j-1;
                // cout<<convert.str()<<" lkl "<<endl;
                convert1<<" ";
                convert1<<i;
                convert1<<" ";
                convert1<<j;
                convert1<<" ";
                convert1<<i;

                string s11=convert1.str();
                //   cout<<s1<<" j-1 "<<s11<<endl;
                if(m[s1]==1||m[s11]==1)goto qw;
                else
                {
                    dp[i][j]=dp[i][j]+dp[i][j-1];
                }

            }
qw:

            if(i-1>=0)
            {
                stringstream convert; // stringstream used for the conversion

                convert<<j;
                // cout<<convert.str()<<" lkl "<<endl;
                convert<<" ";
                convert <<i;
                convert<<" ";
                convert <<j;
                convert<<" ";
                convert <<i-1;
                string s1=convert.str();

                //   cout<<s1<<" s1 "<<endl;



                //  stringstream convert; // stringstream used for the conversion

                stringstream convert1;
                convert1<<j;
                // cout<<convert.str()<<" lkl "<<endl;
                convert1<<" ";
                convert1<<i-1;
                convert1<<" ";
                convert1<<j;
                convert1<<" ";
                convert1<<i;

                string s11=convert1.str();
                //   cout<<s1<<" j-1 "<<s11<<endl;
                if(m[s1]==1||m[s11]==1)continue;
                else
                {
                    dp[i][j]=dp[i][j]+dp[i-1][j];
                }

            }
            //   cout<<dp[i][j]<<" "<<j<<" "<<i<<endl;

        }
        // cout<<endl;
    }
    return dp[height][width];
}


main()
{
    vector<string> s= {"0 0 0 1","6 6 5 6"};
    cout<< numWays(6,6,s);
}
