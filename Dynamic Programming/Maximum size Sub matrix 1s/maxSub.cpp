#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxSubMatrixallones(int matrix[R][C])
{
	int row = R, col = C;
	int sub[row][col];
	int r = 0, c = 0, max_size = 0;

	for(int i=0;i<row;i++)
		sub[i][0] = matrix[i][0];
	for(int j=0;j<col;j++)
		sub[0][j] = matrix[0][j];

	for(int i=1;i<row;i++)
	{
		for(int j=1;j<col;j++)
		{
			if(matrix[i][j] == 1)
				sub[i][j] = min(sub[i-1][j], min(sub[i][j-1], sub[i-1][j-1])) + 1;
			else
				sub[i][j] = 0;
		}
	}
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(sub[i][j] > max_size)
			{
				max_size = sub[i][j];
				r = i, c= j;
			}
		}
	}
	int x = r - max_size, y = c - max_size;
	int area = abs((r - x)*(y - c));
	return area;
}

int main(int argc, char const *argv[])
{
	/* code */
	int M[R][C] =  {{0, 1, 1, 0, 1}, 
                   {1, 1, 0, 1, 0}, 
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
	cout<<"Area is: "<<maxSubMatrixallones(M);
	return 0;
}
