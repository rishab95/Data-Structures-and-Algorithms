#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printboard(vector<vector<int> > &board, int n)
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<" ";
		}			
		cout<<endl;
	}		
}

bool fillboard(vector<vector<int> > &board, int n, int row, int col, int step)
{
	if(step == (n*n + 1))
		return true;
	if(row<0 || row>=n || col<0 || col>=n || board[row][col]!=0)
		return false;

	board[row][col] = step;

	if(fillboard(board, n, row+2, col+1, step+1) == true)
		return true;
	if(fillboard(board, n, row+1, col+2, step+1) == true)
		return true;
	if(fillboard(board, n, row-2, col+1, step+1) == true)
		return true;
	if(fillboard(board, n, row+1, col-2, step+1) == true)
		return true;
	if(fillboard(board, n, row-1, col+2, step+1) == true)
		return true;
	if(fillboard(board, n, row+2, col-1, step+1) == true)
		return true;
	if(fillboard(board, n, row-2, col-1, step+1) == true)
		return true;

	board[row][col] = 0;
	return false;
}

bool knightTour(int n)
{
	vector<vector<int> > board(n, vector<int> (n, 0));

	if(fillboard(board, n, 0, 0, 1) == true)
	{
        for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<board[i][j]<<" ";
			}			
			cout<<endl;
		}		
        return true;
	}

	
	return false;
	//return true;	
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter Board Size: ";
	cin>>n;
	cout<<knightTour(n)<<endl;
	return 0;
}

