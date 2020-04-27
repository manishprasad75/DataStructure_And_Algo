#include<bits/stdc++.h>
using namespace std;

set<vector<int> > s;

void solve(vector<int> &v, int i){
	if(i == v.size()-1){
		s.insert(v);
	}

	for(int j=i;j<v.size();j++){
		swap(v[i], v[j]);
		solve(v, i+1);
		swap(v[i], v[j]); //Backtrack to its original form
	}
}

int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	s.clear();
	solve(v, 0);
	for(vector<int> v : s){
		for(int x : v)
			cout<<x<<" ";
		cout<<endl;
	}
}