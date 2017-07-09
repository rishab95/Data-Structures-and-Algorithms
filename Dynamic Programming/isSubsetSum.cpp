#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isSubsetSum(vector <int> set, int sum)
{
	int n = set.size();
	bool table[sum+1][n+1];

	for(int i=0;i<=n;i++)
		table[0][i] = true;

	for(int i=0;i<=sum;i++)
		table[i][0] = false;	

	for(int i=1;i<=sum;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(set[j-1] <= i)
			{
				table[i][j] = table[i][j-1] || table[i - set[j-1]][j-1];
			}
			else
			{
				table[i][j] = table[i][j-1];
			}
		}
	}
	return table[sum][n];
}

int main()
{
	vector<int> set;
	set.push_back(3);		
	set.push_back(34);
	set.push_back(4);
	set.push_back(12);
	set.push_back(5);
	set.push_back(2);
	int sum;
	cout<<"Enter target sum: ";
	cin>>sum;
	bool ans = isSubsetSum(set, sum);
	cout<<ans<<endl;
	return 0;
}
