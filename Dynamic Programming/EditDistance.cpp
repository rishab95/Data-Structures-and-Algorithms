#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int editdist(string s1, string s2)
{
	int m = s1.length(), n = s2.length();
	int dp[m+1][n+1];
	for(int i=0;i<=m;i++)
		dp[i][0] = i;
	for(int i=0;i<=n;i++)
		dp[0][i] = i;
	for(int i=0;i <= m ;i++){
		for(int j=0;j<=n;j++){
			if(s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
		}
	}	
	return dp[m][n];
}

int main(int argc, char const *argv[])
{
	/* code */
	string A = "cat", B = "cut";
	cout<<"Length is: "<<editdist(A,B)<<endl;
	return 0;
}
