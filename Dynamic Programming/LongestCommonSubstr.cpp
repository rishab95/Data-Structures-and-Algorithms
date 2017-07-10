#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcSub(string s1, string s2)
{
	int m = s1.length(), n = s2.length();
	int dp[m+1][n+1];
	int result = 0;
	for(int i=0;i <= m ;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0)
				dp[i][j] = 0;
			else if(s1[i-1] == s2[j-1])
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
	string A = "AGTXAY", B = "GXTXAYB";
	cout<<"Length is: "<<lcSub(A,B)<<endl;
	return 0;
}
