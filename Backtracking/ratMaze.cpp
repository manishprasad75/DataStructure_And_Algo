//Rat in Maze Problem. Print All the path from the (0,0) to (n-1, n-1). Can Move in all direction.
//		|
//	  <-0-> 
//		|

#include <bits/stdc++.h>
using namespace std;

void printSolution(vector<vector<int> > &v)
{
	for(vector<int> arr : v){
		for(int x : arr)
			cout<<x<<" ";
		cout<<endl;
	}
}

void ratMaze(vector<vector<int> > &maze, int x, int y, vector<vector<int> > &sol)
{
	if(x == maze.size()-1 and y == maze.size()-1 and maze[x][y] == 1){
		sol[x][y] = 1;
		printSolution(sol);
		cout<<"========================="<<endl;
		return;
	}

	if(x<0 || y<0 || x>=maze.size() || y>=maze.size() || maze[x][y] == 0 || sol[x][y] == 1){
		return;
	}

	sol[x][y] = 1;
	ratMaze(maze, x-1, y, sol); //Move Upward
	ratMaze(maze, x+1, y, sol); //Move Downward
	ratMaze(maze, x, y+1, sol); //Move Right
	ratMaze(maze, x, y-1, sol); //Move Left

	sol[x][y] = 0; // After Exploring that shell set it to 0 back.
	return;
}

void solve(vector<vector<int> > &maze)
{
	int n = maze.size();
	vector<vector<int> > sol(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			sol[i].push_back(0);
	}
	ratMaze(maze, 0, 0, sol);
}

int main()
{
	int n;
	cin>>n;
	vector<vector<int> > maze(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int temp;
			cin>>temp;
			maze[i].push_back(temp);
		}
	}

	solve(maze);
}
