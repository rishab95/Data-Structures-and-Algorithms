#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int eqiIndex(int *arr, int n)
{
	//int n = arr.size();
	int totalSum = 0;
	int leftSum = 0;
	int index;

	for(int i=0;i<n;i++)
		totalSum +arr[i];

	for(int i=0;i<n;i++)
	{
		totalSum -=arr[i];

		if(leftSum == totalSum)
		{
			return i;
		}
		else
		{
			leftSum +=arr[i];
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	/* code */
	int arr[] = {-7, 1, 5, 2, -4, 3, 0};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<equiIndex(arr, n);
	return 0;
}
