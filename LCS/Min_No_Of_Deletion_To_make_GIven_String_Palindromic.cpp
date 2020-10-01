#include<bits/stdc++.h>
using namespace std;

int v[10001][10001];

int Min_Del(string s,string p,int n){
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			if(s[i-1] == p[j-1]) v[i][j] = 1 + v[i-1][j-1];
			else v[i][j] = max(v[i][j-1],v[i-1][j]);
		}
	}
	return n - v[n][n];
}

int main(){
	string s= "agbcba";
	string p=s;
	reverse(p.begin(),p.end());
	int n=s.size();
	for(int i=0;i<n+1;i++){
		for(int j=0;j<n+1;j++){
			if(i==0 || j==0) v[i][j]=0;
		}
	}

	cout<<Min_Del(s,p,n)<<endl;
}
