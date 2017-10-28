#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cstring>
using namespace std;


string  result(string S, string T)
{
	vector<int> ans;

	int slen = S.length();
	int tlen = T.length();
	int needtofind[256];
  	memset(needtofind, 0, sizeof(needtofind));
	int hasfound[256];
  	memset(hasfound, 0, sizeof(hasfound));
	for(int i=0;i<tlen;i++)
		needtofind[T[i]]++;
	int wbegin, wend;
	int minwinlen = INT_MAX;
	int count = 0;	

	for(int begin = 0, end = 0; end < slen; end++)
	{
		// Skip those not found
		if(needtofind[S[end]] == 0)
			continue;
		hasfound[S[end]]++;
		if(hasfound[S[end]] <= needtofind[S[end]])
			count++;

		// if window const is met
		if(count == tlen)
		{
			// advance begin to far right satisfying the constraint along side
			while(needtofind[S[begin]] == 0 || hasfound[S[begin]] > needtofind[S[begin]])
			{
				if(hasfound[S[begin]] > needtofind[S[begin]])	
					hasfound[S[begin]]--;
				begin++;
			}
			int winlen = end - begin + 1;
			if(winlen < minwinlen)
			{
				minwinlen = winlen;
				wbegin = begin;
				wend = end;
			}
		}		
	}
	ans.push_back(wbegin);
	ans.push_back(minwinlen);
	return S.substr(wbegin, minwinlen);
}


int main(int argc, char const *argv[])
{
	string s, t;
	cout<<"Enter String\n";
	cin>>s;
	cout<<"Enter Pattern\n";
	cin>>t;
	cout<<result(s, t)<<endl;
	return 0;
}