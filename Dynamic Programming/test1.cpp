#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int minJumps(vector<int> arr, int res[])
{
	int n = arr.size();
	int jumps[n];
	jumps[0] = 0;
	for(int i=1;i<n;i++)
		jumps[i] = INT_MAX;

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[j] + j >= i)
			{
				if(jumps[i] > jumps[j] + 1)
				{
					res[i] = j;
					jumps[i] = jumps[j] + 1;	
				}
			}
		}
	}
	return jumps[n-1];
}

int main(int argc, char const *argv[])
{
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(3);
	arr.push_back(6);
	arr.push_back(1);
	arr.push_back(0);
	arr.push_back(9);
	int n = arr.size();	
	int res[n];
	int ans = minJumps(arr, res);
	cout<<ans<<endl;
	return 0;
}
