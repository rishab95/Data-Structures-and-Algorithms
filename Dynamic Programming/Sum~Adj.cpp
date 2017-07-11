#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sumNotAdj(int arr[], int n)
{
	int incl = arr[0];
	int excl = 0;
	int excl_new;
	for(int i=1;i<n;i++){
		excl_new = (incl > excl) ? incl : excl;

		incl = excl + arr[i];

		excl = excl_new;
	}
	return max(incl, excl);
}

int main(int argc, char const *argv[])
{
	/* code */
	int arr[] = {3,2,5,10,7};
	int n = (sizeof(arr))/(sizeof(arr[0]));
	cout<<"Length is: "<<sumNotAdj(arr,n)<<endl;
	return 0;
}
