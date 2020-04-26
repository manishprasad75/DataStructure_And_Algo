#include <bits/stdc++.h>
using namespace std;

void subSet(vector<int> &v, int index, vector<int> aux)
{
	if(index == v.size()){
		for(int x : aux)
			cout<<x<<" ";
		cout<<endl;
		return;
	}
	aux.push_back(v[index]);  //Include into the aux vector
	subSet(v, index+1, aux);  
	aux.pop_back();  		  //Pop back to backtrack to original vector
	subSet(v, index+1, aux);  //Exclude from the aux vector
}

void solve(vector<int> &v)
{
	vector<int> aux;
	int index = 0;
	subSet(v, index, aux);
}


int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];

	solve(v);
}