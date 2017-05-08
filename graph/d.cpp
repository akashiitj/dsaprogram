#include <iostream>
#include<bits/stdc++.h>
using namespace std;
map<string,string> mymap;
string input;
void func(int i, string str, vector<string> &vec, int n) {
	if(i==n)
	{
		vec.push_back(str);
		return;
	}
	for(int j= i;j<min(i+3,n);j++){
		string s = input.substr(i,j-i+1);
		func(j+1,str+ mymap[s],vec,n);

	}

}
int main() {
	// your code goes here

	cin>>input;
	vector<string> vec;

	mymap["2"] = 'a';
	mymap["22"] = 'b';
    mymap["222"] = 'c';
	int i =0,n=input.size();
	string str;
	func(i,str, vec,n);

	for(int i=0;i<vec.size();i++)
		cout<<vec[i]<<" ";
	cout <<endl;
	return 0;
}
