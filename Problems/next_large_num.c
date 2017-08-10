#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

void nextlargest(string s)
{
	int n = s.length();
	int i, j;
	for(i=n-1;i>0;i++)
	{
		if(s[i] > s[i-1])
			break;
	}
	if(i == 0)
	{
		cout<<"No\n";
		return;
	}
	int temp = s[i-1] , small = i;

	for(j=i+1; j<n; j++)
	{
		if(s[j] > temp && s[j] < s[small])
			small = j;
	}
	swap(s[small], s[i-1]);
	sort(s + i, s + n);
}

int main(int argc, char const *argv[])
{
	/* code */
	string s = "534976";
	return 0;
}
