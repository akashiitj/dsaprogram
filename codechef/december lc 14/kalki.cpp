#include <bits/stdc++.h>
using namespace std;
// Number of vertices in the graph
#define V1 401

// A utility function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST
double dis(double x,double y,double x1,double y1)
{
    return sqrt(((x1-x)*(x1-x))+((y1-y)*(y1-y)));
}
int minKey(int key[], bool mstSet[],int V)
{
   // Initialize min value
   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;

   return min_index;
}
void intia(double graph[V1][V1])
{
   for(int i=0; i<V1; i++)
        {
            for(int j=0; j<V1; j++)
                graph[i][j]=0.0;

        }
}
void intia1(double graph11[],int V)
{
   for(int i=0; i<V; i++)
        {

                graph11[i]=0;

        }
}
// A utility function to print the constructed MST stored in parent[]
int printMST(int parent[], int n, double graph[V1][V1],int V)
{
  // printf("Edge   Weight\n");
   for (int i = 1; i < V; i++)
     cout<<parent[i]+1<<" "<<i+1<<endl;
    //  printf("%d %d\n", parent[i]+1, i+1);
}

// Function to construct and print MST for a graph represented using adjacency
// matrix representation
void primMST(double graph[V1][V1],int V)
{
     int parent[V]; // Array to store constructed MST
     int key[V];   // Key values used to pick minimum weight edge in cut
     bool mstSet[V];  // To represent set of vertices not yet included in MST

     // Initialize all keys as INFINITE
     for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

     // Always include first 1st vertex in MST.
     key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
     parent[0] = -1; // First node is always root of MST

     // The MST will have V vertices
     for (int count = 0; count < V-1; count++)
     {
        // Pick thd minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet,V);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < V; v++)

           // graph[u][v] is non zero only for adjacent vertices of m
           // mstSet[v] is false for vertices not yet included in MST
           // Update the key only if graph[u][v] is smaller than key[v]
          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }

     // print the constructed MST
     printMST(parent, V, graph,V);
}
struct ver
{
    double x;
    double y;
};
int main()
{
     double graph[401][401];
    int t,i,V;
    cin>>t;
    while(t--)
    {
        cin>>V;


        intia(graph);
       // cout<<graph[400][400]<<endl;
       // graph[400][400]=90;
        ver ve[V];

        for( i=0; i<V; i++)
            cin>>ve[i].x>>ve[i].y;
        for( i=0; i<V; i++)
        {
            for(int j=i+1; j<V; j++)
                graph[i][j]=dis(ve[i].x,ve[i].y,ve[j].x,ve[j].y);

        }
         primMST(graph,V);

    }
    return 0;
}


