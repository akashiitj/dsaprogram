#include<bits/stdc++.h>

#define pb push_back

#define mp make_pair

#define all(x) x.begin(),x.end()

#define PII pair<int,int>

#define ft first

#define sd second

#define inf 10000000

using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int P[n][m],W[n][m],MW[n][m];;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>P[i][j];
                MW[i][j]=inf;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>W[i][j];
            }
        }

        int ans;

        vector <pair<int,int> > MS;

        for(int i=0;i<m;i++)
        {
            MW[0][i]=P[0][i];
            MS.push_back(mp(W[0][i],MW[0][i]));
        }

        sort(all(MS));

        for(int i=1;i<n;i++){

            vector<PII > t;

            for(int j=0;j<m;j++){

                t.push_back(mp(P[i][j],j));

            }
            sort(all(t));

            int k=0,l=0,maxx=inf;

            while(l<m){

            while(k<m&&MS[k].ft<=t[l].ft){

                maxx=min(maxx,MS[k].sd-MS[k].ft);
                k++;
            }

            MW[i][t[l].sd]=min(MW[i][t[l].sd],maxx+P[i][t[l].sd]);
            l++;
        }

        k=m-1;
        l=m-1;
        maxx=inf;
        while(l>=0){

            while(k>=0&&MS[k].ft>=t[l].ft)
            {
                maxx=min(maxx,MS[k].sd);
                k--;
            }
            MW[i][t[l].sd]=min(MW[i][t[l].sd],maxx);
            l--;
        }

        MS.clear();

        for(int j=0;j<m;j++){
            MS.push_back(mp(W[i][j],MW[i][j]));
        }

        sort(all(MS));
    }

    ans=inf;
    for(int i=0;i<m;i++)
        ans=min(ans,MW[n-1][i]);

    cout << ans << endl;
}

return 0;

}
