#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lis(int arr[], int n)
{
	int lis[n];
	int result = 0;
	for(int i=0;i<n;i++)
		lis[i] = 1;

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[i] > arr[j] && lis[i] < lis[j] + 1){
				lis[i] = lis[j] + 1;
				result = max(result, lis[i]);
			}
		}
	}
	return  result;
}

int main(int argc, char const *argv[])
{
	/* code */
	int arr[] = {10,22,9,33,21,50,41,60,80};
	int n = (sizeof(arr))/(sizeof(arr[0]));
	cout<<"Length is: "<<lis(arr,n)<<endl;
	return 0;
}
