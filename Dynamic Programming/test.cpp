#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int min_change(vector <int> coins, int target)
{
	int n = coins.size();
	int table[target + 1];
	table[0] = 0;
	for(int i=1; i <= target; i++)
	{
		table[i] = INT_MAX;
	}
	for(int i=1;i<=target;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(coins[j] <= i)
			{
				int temp = table[i - coins[j]];
				if(temp != INT_MAX && temp + 1 < table[i])
				{
					table[i] = temp + 1;
				}
			}
		}
	}
	return table[target];
}

int main()
{
	vector<int> coins;
	coins.push_back(25);
	coins.push_back(10);
	coins.push_back(5);
	int target = 30;
	int n = coins.size();
	int res = min_change(coins, target);
	cout<<res<<endl;
	return 0;
}
