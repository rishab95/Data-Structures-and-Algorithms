#include <iostream>
#include <algorithm>
#include <vector>
//int m = 3, n = 3;
using namespace std;
int getIndex(int i,int j,int rows)
{
	return i*rows + j;
}

void print(int *a, int row, int col)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		cout<<a[i*row+j]<<" ";
		cout<<endl;
	}
}


int minpointsinit(int *points, int m, int n)
{
	int dp[m][n];

	dp[m-1][n-1] = points[getIndex(m-1,n-1,m)]>0 ? 1 : abs(points[getIndex(m-1,n-1,m)]) + 1;

	for(int i=m-2;i>=0;i--)
		dp[i][n-1] = max(dp[i+1][n-1] - points[getIndex(i,n-1,m)], 1);

	for(int j=m-2;j>=0;j--)
		dp[m-1][j] = max(dp[m-1][j+1] - points[getIndex(m-1, j, m)], 1);

	for(int i=m-2;i>=0;i--)
	{
		for(int j=n-2;j>=0;j--)
		{
			int min_exit = min(dp[i+1][j], dp[i][j+1]);

			dp[i][j] = max(min_exit - points[getIndex(i,j,m)], 1);
		}
	}
	
	return dp[0][0];
	//print((int*)dp,m,n)	;
}


int main(int argc, char const *argv[])
{
	/* code */
	int m , n;
	cin>>m;
	cin>>n;
	int points[m][n];
	 /*={{-2,-3,3},
                       {-5,-10,1},
                       {10,30,-5}};*/
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>points[i][j];
    cout<<"Ans: "<<minpointsinit((int*)points, m, n)<<endl;
    print((int*)points,m,n);
	return 0;
}
