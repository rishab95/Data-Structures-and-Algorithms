#include <bits/stdc++.h>
using namespace std;

int count_triplets(vector <int> &arr, int p)
{
	int n = arr.size();
	map<int, int> m;
	int count = 0;
	for(int i=0;i<n;i++)
	{
		m[arr[i]] = i;
	}

	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if((arr[i]*arr[j] < p) && (arr[i]*arr[j] != 0) && (p%(arr[i]*arr[j]) == 0)){
				int var = p / (arr[i]*arr[j]);
				map<int, int> iterator:: it = m.find(var);
				if(var != arr[i] && var != arr[j] && it != m.end() && it->second > i && it->second > j){
					count++;
				}					
			}
		}
	}
	return count;	
}

int main()
{
	vector<int>arr;
	arr.push_back(1);
	arr.push_back(4);
	arr.push_back(6);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(8);
	int p = 24;
	cout<<count_triplets(arr, p);
	return 0;
}	
