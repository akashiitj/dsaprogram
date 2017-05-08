#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i=a;i<b;i++)

vector<vector<int> > e;//vector of  edges    weight ,v1,v2
vector<vector<int> > fe;//edges in MST
int vn;
int en;

int comp[100];

int findcomp(int cv)
{
    int i=cv;
    while(cv!=comp[cv])cv=comp[cv];

    while(i!=cv)//path compressor
    {
        int j=comp[i];
        comp[i]=cv;
        i=j;
    }
    return cv;
}

void union1(int v1,int v2)
{
    v1=findcomp( v1);
    v2=findcomp( v2);
    comp[v1]=v2;
}

void kruskal()
{
    sort(e.begin(),e.end());
    int c=0;
    int i=0;
    while(c!=vn-1)
    {
        // cout<<findcomp(e[i][1])<<" fc "<<findcomp(e[i][1])<<endl
        if(findcomp(e[i][1])!=findcomp(e[i][2]))
        {
            union1(e[i][1],e[i][2]);
            fe.push_back(e[i]);
            c++;
        }
        i++;
    }
}

main()
{
    int w,v1,v2;
    cin>>vn>>en;
    loop(i,0,vn)
    {
        comp[i]=i;
    }
    loop(i,0,en)
    {
        cin>>v1>>v2>>w;
        v1--;
        v2--;
        e.push_back({w,v1,v2});
    }
    kruskal();

    loop(i,0,vn-1)
    cout<<fe[i][0]<<" "<<fe[i][1]<<" "<<fe[i][2]<<endl;
}

//O(ElogE) or O(ElogV). Sorting of edges takes O(ELogE) time. After sorting, we iterate through
// all edges and apply find-union algorithm. The find and union operations can take atmost O(LogV) time.
// So overall complexity is O(ELogE + ELogV) time. The value of E can be atmost O(V2), so O(LogV) are O(LogE) same.
// Therefore, overall time complexity is O(ElogE) or O(ElogV)
