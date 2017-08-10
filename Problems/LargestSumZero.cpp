#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

#include <algorithm>

using namespace std;

typedef map<int, int> mymap;

int  getLargesumzero(vector<int> &arr, mymap &m)
{
	int sum = 0;
	int n = arr.size();
	int mx = 0, f = 0;
	vector<int> ans;
	for(int i=0;i<n;i++)
	{
		sum = sum  + arr[i];

		if(arr[i] == 0 && mx == 0)
		{
			mx = 1;
		}
		if(sum == 0)
			mx = i + 1;

		int prev = m[sum];

		if(m.find(sum) == m.end())
			m[sum] = i;
		else			
			mx = max(mx, i - m[sum]);
		f = i;
	}
	return mx;
}

int main(int argc, char const *argv[])
{
	/* code */
	//15, -2, 2, -8, 1, 7, 10, 23
	vector<int> arr;
	arr.push_back(-15);
	arr.push_back(-2);
	arr.push_back(2);
	arr.push_back(-8);
	arr.push_back(1);
	arr.push_back(7);
	arr.push_back(15);
	arr.push_back(23);
	mymap m1;
	/*vector<int> ans = getLargesumzero(arr, m1);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";*/
	int	ans = getLargesumzero(arr, m1);
	cout<<ans;
	return 0;
}


