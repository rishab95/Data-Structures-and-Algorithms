#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lps(string s)
{
	int res  =0;
	int m = s.length();
	int dp[m+1][m+1];
	for(int i=0;i<=m ;i++){
		for(int j=0;j<=m;j++){
			if(i==0 || j==0)
				dp[i][j] = 0;
			else if(s[i-1] == s[m-j-1])
			{
				dp[i][j] = 1 + dp[i-1][j-1];
				//res = max(res, dp[i][j]);
			}
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}	
	return dp[m][m];
	//return res;
}

int main(int argc, char const *argv[])
{
	/* code */
	string T = "GEEGEEKS";
	cout<<"Length is: "<<lps(T)<<endl;
	return 0;
}
