#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int platforms(int arr[], int dept[], int n)
{
	sort(arr, arr+n);
	sort(dept,dept+n);
	int ans=1;
	int result=1;
	int i=1, j=0;
	while(i<n && j<n){
		if(arr[i] < dept[j])
		{
			ans++;
			i++;
			if(ans > result)
			{
				result = ans;
			}
		}
		else
		{
			ans--;
			j++;
		}
	}  
	return ans;
}

int main()
{
	int n;
	cin>>n;	
	int arr[n], dept[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>dept[i];
	}
	cout<<platforms(arr,dept, n);
	return 0;
}
