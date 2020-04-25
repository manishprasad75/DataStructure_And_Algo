//BackTracking

//Q1. N-Queen Problem

#include <bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<int> > &v){
    int n = v.size();
    for(int i=0;i<n;i++){
        for(int x : v[i])
            cout<<x<<" ";
        cout<<endl;
    }
}

bool isSafe(vector<vector<int> > &v, int row, int col)
{
    int n = v.size();

    //Check if col is safe

    for(int i=0;i<row;i++){
        if(v[i][col] == 1)
            return false;
    }

    //Check if Diagonals are safe
    int i=row;
    int j = col;
    while(i>=0 and j < n){
        if(v[i][j] == 1)
            return false;
        i--;
        j++;
    }

    i = row;
    j = col;
    while(i>=0 and j>=0){
        if(v[i][j] == 1)
            return false;
        i--;
        j--;
    }

    //Col and Diagonals are safe and return true;
    return true;
}

void solveNQueen(vector<vector<int> > &v, int row)
{
    if(row == v.size()){
        // If we can place all the queen in each row
        printBoard(v);
        cout<<"=================="<<endl;
        return;
    }
    for(int i=0;i<v.size();i++){
        if(isSafe(v, row, i)){
            //Safe to place Queen int the given column
            v[row][i] = 1;
            solveNQueen(v, row+1);

            //Backtrack and remove the Queen
            v[row][i] = 0;
        }
    }
}

void solve(int n){
    vector<vector<int> > v(n, vector<int> (n, 0));
    solveNQueen(v, 0);
}

int main()
{
    int n;
    cin>>n;
    solve(n);
}