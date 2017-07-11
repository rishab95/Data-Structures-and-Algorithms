#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int highlowtasks(int low[], int high[], int n)
{
	int prev_pre, prev, curr;
	prev_pre = 0;
	prev = max(low[0], high[0]);

	for(int i=2;i<=n;i++)
	{
		curr = max(low[i-1] + prev, high[i-1] + prev_pre);
		prev_pre = prev;
		prev = curr;
	}
	return prev;
}

int main(int argc, char const *argv[])
{
	/* code */
	int low[] = {1,5,4,6,12};
	int high[] = {3,6,8,7,2};
	int n = sizeof(low)/sizeof(low[0]);
	cout<<highlowtasks(low,high,n)<<endl;
	return 0;
}
