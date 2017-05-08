#include<iostream>
using namespace std;


main(){
    int n;cin>>n;
for(int i=0;i<n;i++)
{int gl,bl,br,gr;
 cin>>gl>>gr;
 cin>>bl>>br;
 if(gl<=br&&br<=((2*gl)+2)||gr<=bl&&bl<=((2*gr)+2))cout<<"YES";
 else cout<<"NO";
}
}
