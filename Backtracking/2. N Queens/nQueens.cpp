#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int> > &board, int col, int row, int n)
{
	for(int i=0;i<col;i++) //Check Row;
		if(board[row][i])
			return false;
	for(int i=row, j=col;i>=0 && j>=0;i--, j--)
		if(board[i][j])
			return false;
	for(int i=row, j=col;j>=0 && i<n;i++, j--)
		if(board[i][j])
			return false;
	return true;
}	

bool placeQueen(vector<vector<int> > &board, int col, int n)
{
	if(col>=n)
		return true;

	for(int row = 0;row < n; row++)
	{
		if(isSafe(board, col, row, n))
		{
			board[row][col] = 1;
			if(placeQueen(board, col + 1, n))
			{
				return true;
			}
			board[row][col] = 0;
		}
	}
	return false;
}

void printboard(vector<vector<int> > &board, int n)
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<" ";
		}			
		cout<<endl;
	}		
}

bool nqueen(int n)
{
	vector<vector<int> > board(n, vector<int> (n, 0));

	if(placeQueen(board, 0, n) == false) // 0 is starting col, n is total no.
		return false;

	printboard(board, n);
	return true;
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter Board Size: ";
	cin>>n;
	cout<<nqueen(n)<<endl;
	/* code */
	return 0;
}
