#include<bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pii pair<int,int>

int prnt[1001];
int vis[1001];

void initialise(){
    for(int i=0;i<=1000;i++){
        prnt[i]=i;
        vis[i]=0;
    }
}
int obnumberofroot(int obn)//pass objectnumber of object whose root we have to fing
{   int i=obn;
    while(prnt[obn]!=obn)obn=prnt[obn];
    //obn is now root object no
    while(i!=obn)//doing path compressing
    {
        int j=prnt[i];
        prnt[i]=obn;
        i=j;
    }
    return obn;
}
int find(int i,int j)
{
    return (obnumberofroot(i)==obnumberofroot(j));
}
void unionbyobnumber(int i,int j)
{
    int x=obnumberofroot( i);
    int y=obnumberofroot( j);
    //now all those object whose pindex is y we make it x
    prnt[y]=x;
}

bool findBlockage(int root,int X,int Y,int N,int R,vector<pair<int,pii>>vec){
    int top=0;
    int bottom=INT_MAX;
    int left=INT_MAX;
    int right=0;

    for(int i=0;i<N;i++){
        if(prnt[vec[i].first]==root){
            vis[prnt[vec[i].first]]=1;
            int x=vec[i].second.first;
            int y=vec[i].second.second;
            top=max(top,y+R);
            bottom=min(bottom,y-R);
            left=min(left,x-R);
            right=max(right,x+R);
        }
    }
    if(top>=Y and bottom<=0)return true;
    if(right>=X and left<=0)return true;
    if(top>=Y and right>=X)return true;
    if(left<=0 and bottom<=0)return true;
    return false;
}

string Solution::solve(int X, int Y, int N, int R, vector<int> &E, vector<int> &F) {
    vector<pair<int,pii> > vec;
    for(int i=0;i<N;i++){
        vec.push_back({i,{E[i],F[i]}});
    }

    initialise();

    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            if(i==j)continue;
            int x1=vec[i].second.first;
            int x2=vec[j].second.first;

            int y1=vec[i].second.second;
            int y2=vec[j].second.second;

            if(((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)) <= (4*R*R)){
                unionbyobnumber(vec[i].first,vec[j].second)
            }
        }
    }

    for(int i=0;i<N;i++){
        if(!vis[prnt[vec[i].first]]){
            vis[prnt[vec[i].first]]=1;
            bool ret = findBlockage(prnt[vec[i].first],X,Y,N,R,vec);
            if(ret)return "NO";
        }
    }
    return "YES";
}





