#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>


using namespace std;

bool isInterleaved(string A, string B, string C)
{
	int alen = A.length(), blen = B.length(), clen = C.length();
	bool dp[alen+1][blen+1];
	memset(dp, 0, sizeof(dp));

	if((alen + blen) != clen)
		return false;
	for(int i=0;i<=alen;i++)
	{
		for(int j=0;j<=blen;j++)
		{
			// both the A n B are empty
			if(i==0 && j==0)
				dp[i][j] = true;
			//A is empty
			else if(i==0 && B[j-1] == C[j-1])
				dp[i][j] = dp[i][j-1];
			//B is empty
			else if(j==0 && A[i-1] == C[i-1])
				dp[i][j] = dp[i-1][j];
			//C is interleaved with A but not B;
			else if(A[i-1] == C[i+j-1] && B[j-1] != C[i+j-1])
				dp[i][j] = dp[i-1][j];
			else if(B[j-1] == C[i+j-1] && A[i-1] != C[i+j-1])
				dp[i][j] = dp[i][j-1];
			else
				dp[i][j] = dp[i-1][j] || dp[i][j-1];;
		}
	}
	return dp[alen][blen];
}

int main(int argc, char const *argv[])
{
	string a, b, c;
	cin>>a>>b>>c;
	cout<<isInterleaved(a, b, c)<<endl;
}




for(int a0 = 0; a0 < t; a0++)
        {
            long n = in.nextLong(); 
           long n1=0,n2=0,n3=0;
          n1=n/3;
            n1=3*n1*(n1+1)/2;
          n2=n/5-1;
            n2=5*n2*(n2+1)/2;
         n3=n/15;
            n3=15*n3*(n3+1)/2;
        System.out.println(n1+n2-n3);