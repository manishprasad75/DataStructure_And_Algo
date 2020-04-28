#include <bits/stdc++.h>
using namespace std;

set<vector<int>  >s;


//s - set which is use to store the answer in order (containing no dublicate)
//v - Original Vector
//index - Current Position
// sum - Sum of element int the aux vector
//aux - Temparory vector containing the included element
//target - Target sum which we required

void subSet(vector<int> &v, int index, int sum, vector<int> aux, int target)
{
	if(sum == target){  // If we found the target sum
		s.insert(aux); //aux vector contain the subset which sum up to target
		return;
	}
	if(index == v.size()) //If we reach the last element, we return
		return;
	aux.push_back(v[index]); // Include in the aux
	subSet(v, index+1, sum+v[index], aux, target); //Included in the aux
	aux.pop_back(); // BackTraking Step (Exclude from the aux vector);
	subSet(v, index+1, sum, aux, target); //Exclude from the aux vector;
	return;
}

int main()
{
	int n,target;
	cin>>n>>target;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	vector<int> aux;
	s.clear();
	subSet(v, 0, 0, aux, target);
	for(vector<int> v : s){
		for(int x : v)
			cout<<x<<" ";
		cout<<endl;
	}
}