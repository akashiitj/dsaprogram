#include<bits/stdc++.h>
using namespace std;
long long number(string s1, string s2,long long ic,long long rc,long long k) {
	long long len1 = s1.size(), len2 = s2.size();
	vector<long long> col(len2+1), prevCol(len2+1);

	for (long long i = 0; i < prevCol.size(); i++)
		prevCol[i] = i;
	for (long long i = 0; i < len1; i++) {
		col[0] = i+1;
		for (long long j = 0; j < len2; j++)
			{col[j+1] = min( min(prevCol[1 + j] + ic, col[j] + ic),prevCol[j] + (s1[i]==s2[j] ? 0 : rc) );
           if(col[j+1]>k)return -1;
            }
		col.swap(prevCol);

	}

	return prevCol[len2];
}
main()
{   ios_base::sync_with_stdio(false);
     string s1,s2;

long long ic,rc,k;
     long long t;
     cin>>t;
     while(t>0){
    cin>>s1;
    cin>>s2;
    cin>>ic;
    cin>>rc;
    cin>>k;
    cout<<number(s1,s2,ic,rc,k)<<endl;
     t--;
     }
}
