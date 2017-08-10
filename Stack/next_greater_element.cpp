#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int nge(vector<int> &arr)
{
	int n = arr.size();
	stack<int> s;
	s.push(arr[n-1]);
	arr[n-1] = -1;
	for(int i=n-2;i>=0;i--)
	{
		int t = s.top();
		while(t <= arr[i])
		{
			s.pop();
			if(s.empty())
			{
				t = -1;
				break;
			}
			t = s.top();
		}
		s.push(arr[i]);
		arr[i] = t;
	}
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}

int main(int argc, char const *argv[])
{
	/* code */
	int n;
	cin>>n; 
	vector<int> arr;
	arr.resize(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	nge(arr);
	//cout<<ans<<" ";
	return 0;
}
