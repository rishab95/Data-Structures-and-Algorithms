#include <bits/stdc++.h>
using namespace std;

int count_triplets(vector <int> &arr)
{
	int n = arr.size();
	int count = 0, max = 0;
	for(int i=0;i<n;i++)
	{
		if(arr[i] == 1)
		{
			count++;
		}
		else if(arr[i]==0)
		{
		 	if(max < count)	
	 		{
	 			max = count;
		 	}
		 	count  = 0;
		}		
	}
	return count;	
}

int main()
{
	vector<int>arr;
	arr.push_back(1);
	arr.push_back(0);
	arr.push_back(0);
	arr.push_back(0);
	arr.push_back(1);
	arr.push_back(1);
	//int p = 24;
	cout<<count_triplets(arr);
	return 0;
}	
