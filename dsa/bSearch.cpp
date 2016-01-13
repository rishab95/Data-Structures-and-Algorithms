#include <iostream>
using namespace std;

int bSearch(int ar[], int e, int l, int h)
{
	if(l<=h)
	{
		int m = (l+h)/2;
		

		if(ar[m] ==e)
			return m;
		if(ar[m] > e)
			return bSearch(ar, e, l, m-1);
		else
			return bSearch(ar, e, m+1, h);
	}
	return -1;
} 

int main(int argc, char const *argv[])
{
	int arr[] = {2, 3, 4, 5, 6};
	int as = sizeof(arr)/sizeof(arr[0]);
	int e = 10;
	int result = bSearch(arr, e, 0, as-1);
//	(result == -1)? cout<<"Element is not present in array": cout<<"Element is present at index"<<"  "<<result;
	/* code */
	if (result != -1)
    	cout<< "Element is present at index "<<" "<<result;
	else
    	cout<<"Element is not present in array";
	return 0;
}
