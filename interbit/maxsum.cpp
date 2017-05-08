#include<bits/stdc++.h>
using namespace std;

string largestNumber(const vector<int> &A) {

    vector<string> a;
    int n=A.size();
    for(int j=0; j<n; j++)
    {
        int x=A[j];
        string s1;
        while(x>0)
        {
            s1=s1+(char)(x%10+'0');
            x=x/10;

        }
        reverse(s1.begin(),s1.end());
        // cout<<s1<<" ";
        a.push_back(s1);
    }
    sort(a.rbegin(),a.rend());


    string ans;
    int i=0;

    int j;
    while(i<n)
    {
        int hv=atoi(a[i].c_str());
        if(hv%10==0)
        {
            j=i+1;
            int hv1=atoi(a[j].c_str());
            while(j<n&& hv/10==hv1)
            {


                ans=ans+a[j];
                j++;
                hv1=atoi(a[j].c_str());

            }
            ans=ans+a[i];
            i=j;
        }
        else
        {

            ans=ans+a[i];
            i++;
        }
       // cout<<ans<<"\n";
    }
    return ans;

}


main()
{
    vector<int > a= {3, 30, 34, 5, 9 };
    string s=largestNumber(a);

    cout<<s<<"\n";
}
