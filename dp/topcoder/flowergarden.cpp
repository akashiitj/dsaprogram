#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,b) for(int i = a; i < b; i++)
int used[55];

vector <int> getOrdering(vector <int> height, vector <int> bloom, vector <int> wilt)
{
    vector<int > h;
    int n=height.size();
    int maxh=-1,pos;
    loop(i,0,n)
    {
        maxh=-1;
        pos=-1;
        loop(j,0,n)
        {
            if(used[j])continue;
            int canitbecandidate=1;
            loop(k,0,n)
            {
                if(used[k])continue;
                if(j!=k&&height[j]>height[k])//jth flower can block kth one
                {
                    int ifblocking=((wilt[j]<bloom[k]) || (bloom[j]>wilt[k]) );//1 means its not blocking
                    if(ifblocking==0)
                    {

                        canitbecandidate=0;
                        break;//means j cannt be candidate as it is blockin k
                    }
                }
            }
            if(canitbecandidate==1)
            {
                if(maxh<height[j])//finding optimal one jo jo block nahi karrahe kisi ko bhi unme se max heigth wala
                {
                    maxh=height[j];
                    pos=j;
                }

            }
        }
        if(pos==-1)//means perfect candidate is of smaller height because all are blocking each other
        {
            int min1=10000;
            pos=-1;
            loop(i,0,n)
            {
                if(used[i]==0&&min1>height[i])
                {
                    min1=height[i];
                    pos=i;
                }
            }
        }
        h.push_back(height[pos]);
        used[pos]=1;
    }
    return h;
}
vector <int> getOrdering1(vector <int> height, vector <int> bloom, vector <int> wilt)//someone solution
{
    vector<bool> used = vector<bool>(height.size());
    vector<int> res;
    for (size_t i=0; i<height.size(); ++i)
    {
        int mxH = 0;
        int pos = -1;
        for (size_t j=0; j<height.size(); ++j)
        {
            if (used[j]) continue;
            bool found = true;
            for (size_t k=0; k<height.size(); ++k)
            {
                if (used[k]) continue;
                bool blocking = !(wilt[j]<bloom[k] || (bloom[j]>wilt[k]) );
                if( (height[j]>height[k]) && blocking )
                {
                    found = false;
                    break;
                }
            }
            if ( found && (mxH<height[j]) )
            {
                mxH = height[j];
                pos = j;
            }
        }
        cout<<pos<<endl;
        res.push_back(height[pos]);
        used[pos] = true;
    }
    return res;
}

main()
{
    vector<int > hei= {1,2,3,4,5,6};



    vector<int > b= {1,1,1,1,1,1};
    vector<int > d= {2,2,2,2,2,2};
    vector<int > ans=getOrdering(hei,b,d);

    loop(i,0,ans.size())
    cout<<ans[i]<<" ";

}
