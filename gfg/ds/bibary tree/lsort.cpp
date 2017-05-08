#include<bits/stdc++.h>
#include <stdlib.h>

using namespace std;
int a[1010], pos[1010];

int best[1010][1010], bef[1010][1010];//it means i value jaha par hai usse left side me j aur usse smaller kitne element hai
//1,3,2,5,4;
//bef[4][3]=3 ie 1 2 3
//bef[2][3]=2 ie 1 3

int main(void)
{
    int i, j, l, N, T, x, y;

    scanf("%d", &T);

    while(T--)
    {
        scanf("%d", &N);

        for (i=1; i<=N; i++)
        {
            scanf("%d", &a[i]);

            pos[a[i]] = i;
        }

        for (i=1; i<=N; i++)
        {
            bef[i][0] = 0;

            for (j=1; j<=N; j++)
            {
                bef[i][j] = bef[i][j-1];

                if ( pos[j] < pos[i] ) bef[i][j]++;
            }
        }
        cout<<"\n";

        for (i=1; i<=N; i++)
        {


            for (j=1; j<=N; j++)
            {
                cout<<bef[i][j]<<" ";
            }
            cout<<"\n";
        }

cout<<"\n";

        for (i=1; i<=N; i++ )
        {
            best[i][i] = pos[i];
        }

        for (l=2; l<=N; l++)
        {
            for (i=1; i<=N-l+1; i++)
            {
                j = i+l-1;

                x = best[i+1][j] + l * (pos[i] - (bef[i][j]  -  bef[i][i]));
                y = best[i][j-1] + l * (pos[j] - (bef[j][j-1]-bef[j][i-1]));

                if ( x < y ) best[i][j] = x;
                else best[i][j] = y;

                cout<<best[i][j]<<" ";
            }
            cout<<"\n";
        }

        printf("%d\n", best[1][N]);
    }

    return 0;
}
