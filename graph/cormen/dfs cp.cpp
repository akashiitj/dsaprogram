#include<bits/stdc++.h>

using namespace std;
//int visit[4]= {0};

#define loop(i,a,b)      for(int i=a;i<b;i++)

int time1=0;

struct node
{
    int vn;//vertex no
    int vv;//vertex value
    node* ptav;//pointing to adjacent vertex
};

struct vi//vertex information when searched from a given sourece
{
    int pi;//parent index
    int intime1;
    int outtime1;
};

node v[1000];
vi vidfs[1000];

int n;//total no of nodes

vector<int> component[500];//keep maximal connected component
int comno=0;

void addedge(int i,int j)// i and j are node number
{
    node *n1=new node;
    n1->ptav=v[i].ptav;
    n1->vn=j;
    n1->vv=v[j].vv;
    v[i].ptav=n1;
}


int visit[1000]= {0};



void dfs(int svn)//source vertex no
{
    component[comno].push_back(svn);
    visit[svn]=1;
    vidfs[svn].intime1=time1;
    time1++;
    node *n1=v[svn].ptav;
    while(n1!=NULL)
    {
        if(visit[n1->vn]==0)
        {
            vidfs[n1->vn].pi=svn;
            dfs(n1->vn);

        }
        n1=n1->ptav;
    }
    vidfs[svn].outtime1=time1;
    time1++;
}



void show()
{
    //graph printing
    for(int i=0; i<n; i++)//see how to pass size since gp is pointer so we cant use gp.length
    {
        node *hp=v[i].ptav;
        cout<<v[i].vn<<"  ";
        while(hp!=NULL)
        {
            cout<<hp->vn<<"  ";
            hp=hp->ptav;
        }
        cout<<endl;
    }
}
main()
{
    int v1,v2;
    cout<<"enter total no of nodes"<<endl;
    cin>>n;
    cout<<"enter values of nodes"<<endl;
    loop(i,0,n)
    {
        cout<<i<<": ";
        cin>>v[i].vv;
        v[i].vn=i;
        v[i].ptav=NULL;
    }
    cout<<"enter 2 vertex no in which you wanted to add edge and type -1 to end"<<endl;
    while(true)
    {
        cin>>v1;
        if(v1==-1)break;
        cin>>v2;
        addedge(v1,v2);
        addedge(v2,v1);
    }
    show();

    loop(i,0,n)
    {
        if(visit[i]==0)
        {   vidfs[i].pi=-1;
            dfs(i);
            comno++;
        }
    }

    loop(i,0,n)
    {
        cout<<vidfs[i].pi<<" "<<vidfs[i].intime1<<" "<<vidfs[i].outtime1<<endl;
    }
    loop(i,0,n)
    {
       cout<< component[0][i]<<" ";
    }

}


