#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <string>


using namespace std;


int binarysearch(vector <string> arr, string str, int first, int last)
{
	//int first = 0, last = arr.size() - 1;
	if(first > last)
		return -1;
	int mid = (first + last) / 2;

	if(arr[mid] == "")
	{
		int left = mid - 1;
		int right = mid + 1;
		while(true)
		{
			if(left < first && right > last)
				return -1;
			else if(left >= first && arr[left] != "")
			{
				mid = left;
				break;
			}
			else if(last <= right && arr[right] != "")
			{
				mid = right;
				break;
			}
			right++;
			left--;
		}
	}
	if(arr[mid] == str)
		return mid;
	else if(arr[mid].compare(str) < 0)
		return binarysearch(arr, str, mid + 1, last);
	else
		return binarysearch(arr, str, first, mid - 1);
}

int search(vector <string> arr, string str)
{
	if(arr.size() == 0 || str == "")
		return -1;

	return binarysearch(arr,str,0,arr.size() - 1);
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter n:";
	cin>>n;
	string str;
	cout<<"Enter array: ";
	vector <string> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
		/* code */
	}
	cout<<"Enter str: ";
	cin>>str;
	int ans = search(arr, str);
	cout<<ans<<endl;
	return 0;
}