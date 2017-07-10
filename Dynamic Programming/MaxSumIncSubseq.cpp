#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sumLis(int arr[], int n)
{
	int lisSum[n];
	int result = 0;
	for(int i=0;i<n;i++)
		lisSum[i] = arr[i];

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[i] > arr[j] && lisSum[i] < lisSum[j] + arr[i]){
				lisSum[i] = lisSum[j] + arr[i];
				result = max(result, lisSum[i]);
			}
		}
	}
	return  result;
}

int main(int argc, char const *argv[])
{
	/* code */
	//int arr[] = {10,22,9,33,21,50,41,60,80};
	int arr[] = {1,101,2,3,100,4,5};
	int n = (sizeof(arr))/(sizeof(arr[0]));
	cout<<"Length is: "<<sumLis(arr,n)<<endl;
	return 0;
}
