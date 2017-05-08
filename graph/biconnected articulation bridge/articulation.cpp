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
    int minbe;//keep record of minimum vertex no to which backedge exist
    int outtime1;
};

node v[1000];
vi vidfs[1000];
int n;//total no of nodes

void addedge(int i,int j)// i and j are node number
{
    node *n1=new node;
    n1->ptav=v[i].ptav;
    n1->vn=j;
    n1->vv=v[j].vv;
    v[i].ptav=n1;
}

int visit[1000]= {0};
vector<int> ap;

void dfsap(int svn)//source vertex no
{
    int child=0;
    time1++;
    visit[svn]=1;
    vidfs[svn].intime1=time1;
    vidfs[svn].minbe=time1;
    node *hp=v[svn].ptav;
    while(hp!=NULL)
    {
        int cvn=hp->vn;
        if(visit[cvn]!=1)
        {
            child++;
            vidfs[cvn].pi=svn;
            dfsap(cvn);
            vidfs[svn].minbe=min( vidfs[svn].minbe,vidfs[cvn].minbe);//used for nxt iteration
            cout<<svn<<" "<<cvn<<"\n";
            if(vidfs[svn].pi==-1&&child>1)//root is ap if it has more than two child
                ap.push_back(svn);
            if(vidfs[svn].pi!=-1&&vidfs[svn].intime1<=vidfs[cvn].minbe)//it means cvn or from its below their is bacedge below(=) svn so svn is ap
                ap.push_back(svn);
        }
        else if(vidfs[svn].pi!=cvn)//if bacha is already visited
        {
            vidfs[svn].minbe=min(vidfs[svn].minbe,vidfs[cvn].intime1);
        }
        hp=hp->ptav;
    }
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
            //cout<<hp->vn<<"  ";
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
    //cout<<"enter values of nodes"<<endl;
    loop(i,0,n)
    {
        cout<<i<<": ";
        //   cin>>v[i].vv;
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
        {
            vidfs[i].pi=-1;
            dfsap(i);

        }
    }

    loop(i,0,ap.size())
    cout<<"\n"<<ap[i]<<"     ";

}


