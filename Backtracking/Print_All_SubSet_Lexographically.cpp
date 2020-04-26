#include <bits/stdc++.h>
using namespace std;
set<string> s;

void subSequence(string st, int index, string aux)
{
	if(index == st.length()){
		s.insert(aux);
		return;
	}

	subSequence(st, index+1, aux+st[index]);
	subSequence(st, index+1, aux);
}

void solve(string st)
{
	int index = 0;
	string aux="";
	subSequence(st, index, aux);
}
int main()
{
	s.clear();
	string st;
	cin>>st;
	solve(st);
	for(auto x : s)
		cout<<x<<endl;
	cout<<endl;

}