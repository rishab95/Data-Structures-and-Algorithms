#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sumLis(int arr[], int n)
{
	int lis[n], lds[n];
	int result = 0;
	for(int i=0;i<n;i++)
		lis[i] = lds[i] = 1;

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[i] > arr[j] && lis[i] < lis[j] + 1){
				lis[i] = lis[j] + 1;				
			}
		}
	}
	for(int i=n-2;i>0;i--){
		for(int j=n-1;j>i;j--){
			if(arr[i] > arr[j] && lds[i] < lds[j] + 1){
				lds[i] = lds[j] + 1;				
			}
		}
	}	
	result = lis[0]	+ lds[0] - 1;
	for(int i=0;i<n;i++){
		if(lis[i] + lds[i] - 1 > result){
			result = lis[i] + lds[i] - 1;
		}			
	}
	return result;
}

int main(int argc, char const *argv[])
{
	/* code */
	//int arr[] = {10,22,9,33,21,50,41,60,80};
	//int arr[] = {1,101,2,3,100,4,5};
	int arr[] = {1,11,2,10,4,5,2,1};
	int n = (sizeof(arr))/(sizeof(arr[0]));
	cout<<"Length is: "<<sumLis(arr,n)<<endl;
	return 0;
}
