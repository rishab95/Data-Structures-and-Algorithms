#include <iostream>
#include <algorithm>

using namespace std;

int longest_palin_substr(string s)
{
 	int n = s.length();
 	bool palin[n+1][n+1];
 	int max_len = 1;
 	int palin_begin = 0;
 	
 	for(int i=0;i<=n;i++)
	{
		palin[i][i] = true;		
	}
 	
 	for(int i=0;i<n-1;i++)
 	{
 		if(s[i] == s[i+1])
 		{
 			palin[i][i+1] = true;
 			palin_begin = i;
 			max_len = 2;
 		}
 	}
 	
	for(int curr = 3;curr <= n; curr++)
	{
		for(int i = 0;i < n - curr + 1;i++)
		{
			int j = i + curr  - 1;
			if(s[i] == s[j] && palin[i+1][j-1])
			{
				palin[i][j] = true;
				palin_begin = i;
				max_len = curr;
			}
		}
	}
 	return max_len;
}

int main()
{
	string s;
	s = "BANANANANANANANAS";
	cout<<"Length is : "<<longest_palin_substr(s)<<endl;
	return 0;
}
