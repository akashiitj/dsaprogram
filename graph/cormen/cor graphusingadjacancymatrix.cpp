#include<iostream>
#include <string.h>
//passing two d pointer important
using namespace std;
class graphc
{   public:
    int returnindexofarraycorrespondingtokey(int a[],int lengthofarray,int valueofvertex)
    {
        for(int i=0; i<lengthofarray; i++)
            if(a[i]==valueofvertex)return i;
    }
    void addedge(int *dg,int viwwwta,int vtba,int a[],int lengthofarra)//vertex in which we want to add;vertex to be added
    {
        dg[(returnindexofarraycorrespondingtokey(a,lengthofarra,viwwwta))*lengthofarra+ returnindexofarraycorrespondingtokey(a,lengthofarra,vtba)]=1;
    }
};
main()
{   graphc go;
int v;
    cout<<"enter no of vertices in graph";
    cin>>v;
    int ar[v];
    for(int i=0; i<v; i++)
    {
        cout<<"enter value of "<<i<<" vertex";
        cin>>ar[i];
    }
    int  graph[v][v];
    memset(graph, 0, sizeof(graph[0][0])* v * v);//to intialise all element of array =0;
    go.addedge(&graph[0][0],2 ,1,ar,v);

	for(int i=0; i<v; i++)    //This loops on the rows.
	{
		for(int j=0; j<v; j++) //This loops on the columns
		{
			cout << graph[i][j]  << "  ";
		}
		cout << endl;
	}
}

