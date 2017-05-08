#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define loop(i,a,b) for(int i=a;i<b;i++)

main()
{
    int t,n,x,cs,flag;
    cin>>t;
    vector<pair<int,int> >v;//first element means frequency,second element means index
    while(t--)
    {
        cs=0;
        flag=0;
        v.clear();
        cin>>n;
        int ans[n+1];
        loop(i,0,n)
        {
            cin>>x;
            cs=cs+x;
            if(x==n)flag=1;
            v.push_back(make_pair(x,i+1));
        }
        if(flag==1||cs!=n)
        {
            cout<<-1<<endl;
            continue;
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());

//        loop(i,0,n)
//        cout<<v[i].first<<" "<<v[i].second<<endl;
//
//        cout<<endl;
        int si=1;//start filling from second most fequent voting person
        loop(i,0,n)
        {
            int c=v[i].first;
            if(c==0)break;//inhe koi vote hi nahi maile
            if(si==n)//means hamne sab place fill kar di except jise sabse jyada vote mile hai uski
            {
                ans[v[0].second]=v[i].second;
            }
            else if(c!=0)
            {
                loop(j,0,c)
                {
                    ans[v[si].second]=v[i].second;
                    si++;
                    if(si==n)//you forget it
                    {

                        ans[v[0].second]=v[i].second;
                        break;
                    }
                }
            }
//            loop(i,0,n)
//            cout<<ans[i+1]<<" ";
//            cout<<endl;

        }
        loop(i,0,n)
        cout<<ans[i+1]<<" ";
        cout<<endl;
    }
}
