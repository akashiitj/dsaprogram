#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


#define loop(i,a,b)      for(int i=a;i<b;i++)

int gridColouring(vector < string > grid)
{
    int n=grid.size();
    int m=grid[0].size();
    int min_strokes=0;

    int blue[n+1][m+1],red[n+1][m+1];
    memset(blue,0,sizeof blue);
    memset(red,0,sizeof red);


    loop(i,0,n)
    loop(j,0,m)
    {
        if(grid[i][j]=='G'||grid[i][j]=='B')
        {
            if(blue[i][j]==0)
            {
                min_strokes++;
                for(int i1=i; i1>=0; i1--)
                {
                    // cout<<i1<<" "<<j<<" 1\n";
                    if(grid[i1][j]=='G'||grid[i1][j]=='B')
                        blue[i1][j]=1;
                    else break;
                }
                for(int i1=i; i1<n; i1++)
                {
                    // cout<<i1<<" "<<j<<" 2\n";
                    if(grid[i1][j]=='G'||grid[i1][j]=='B')
                        blue[i1][j]=1;
                    else break;
                }
            }
        }

        if(grid[i][j]=='G'||grid[i][j]=='R')
        {
            if(red[i][j]==0)
            {
                min_strokes++;
                for(int j1=j; j1>=0; j1--)
                {
                    if(grid[i][j1]=='G'||grid[i][j1]=='R')
                        red[i][j1]=1;
                    else break;
                }
                for(int j1=j; j1<m; j1++)
                {
                    if(grid[i][j1]=='G'||grid[i][j1]=='R')
                        red[i][j1]=1;
                    else break;
                }
            }
        }


    }

    //cout<<min_strokes<<"\n";

    return min_strokes;
}
int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;

    int _grid_size = 0;
    cin >> _grid_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<string> _grid;
    string _grid_item;
    for(int _grid_i=0; _grid_i<_grid_size; _grid_i++) {
        getline(cin, _grid_item);
        _grid.push_back(_grid_item);
    }

    res = gridColouring(_grid);
    cout << res << endl;

    fout.close();
    return 0;
}
