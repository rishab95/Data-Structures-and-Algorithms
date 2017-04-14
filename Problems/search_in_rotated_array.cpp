//find element in an rotated array

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int find(vector <int> arr, int val)
{
	int low = 0, high = arr.size()-1;
	while(low <= high)
	{
		int mid = (low + high) / 2;
		if(val == arr[mid])
			return mid;

		if(arr[mid] >= arr[high])
		{
			if(val <= arr[mid] && arr[low] <= val)
			{
				high = mid - 1;
			}
			else
			{
				//wen val is between mid and high
				low = mid + 1;
			}
		}
		else
		{
			if(val >= arr[mid] && val <= arr[high])
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int n, val;
	cin>>n;
	vector <int> arr(n);
	for(int i = 0;i < n; i++)
		cin>>arr[i];
	cout<<"enter target: ";
	cin>>val;
	int ans = find(arr, val);
	cout<<ans<<endl;
	return 0;
}

