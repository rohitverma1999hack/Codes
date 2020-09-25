#include<bits/stdc++.h>
using namespace std;

vector<vector<int > > v;

int LCSS(string s,string p,int n,int m){
	int maxx=0;
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			if(s[i-1] == p[j-1]) {
				v[i][j] = 1 + v[i-1][j-1];
				maxx=max(maxx,v[i][j]);
			}else {
				v[i][j] = 0;
			}
		}
	}
	return maxx;
}

int main(){

	string s="abcde";
	string p="abfce";
	int n=s.size();
	int m=p.size();

	v.resize(n+1,vector<int>(m+1));

	for(int i=0;i<n+1;i++){
		for(int j=0;j<m+1;j++){
			if(i==0 || j==0) v[i][j]=0;
		}
	}

	cout<<LCSS(s,p,n,m)<<endl;
}
