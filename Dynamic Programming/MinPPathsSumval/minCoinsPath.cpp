#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef vector<vector<vector<int> > > vec;

//vec dp(m, vector<vector<int> >(n,vector<int>(target,-1)));
int dp[100][100][100];

int pathcount(vector<vector<int> > &mat, int m, int n, int k)
{
	if(m<0 || n <0 || k<0)
		return 0;

	if(m == 0 && n == 0)
		return (k == mat[m][n]);

	if(dp[m][n][k] != -1)
		return dp[m][n][k];

	dp[m][n][k] = pathcount(mat, m-1, n, k - mat[m][n]) + pathcount(mat, m, n-1, k - mat[m][n]);

	return dp[m][n][k];
}

int func(vector<vector<int> > &pts, int target)
{
	int m = pts.size(), n = pts[0].size();	
	memset(dp, -1, sizeof(dp));
	return pathcount(pts, m-1, n-1, target);

	/*for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<target;k++)
			{
				cout<<dp[i][j][k]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}*/
}

int main()
{
	int m, n;
	cin>>m>>n;
	vector<vector<int> >mat(m, vector<int> (n, 0));
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>mat[i][j];

	cout<<func(mat, 12);
}


