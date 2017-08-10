#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lpSub(string s)
{
	int m = s.length();
	int dp[m+1][m+1];
	int result = 0;
	for(int i=0;i<=m ;i++){
		for(int j=0;j<=m;j++){
			if(i==0 || j==0)
				dp[i][j] = 0;
			else if(s[i-1] == s[m-j-1])
			{
				dp[i][j] = 1 + dp[i-1][j-1];
				result = max(result, dp[i][j]);
			}
			else
				dp[i][j] = 0;
		}
	}	
	return result;
}

int main(int argc, char const *argv[])
{
	/* code */
	string T = "BXACBCABBA";
	cout<<"Length is: "<<lpSub(T)<<endl;
	return 0;
}