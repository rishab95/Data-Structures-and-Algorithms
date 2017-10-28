#include<iostream>

using namespace std;

void next(int arr[], int n)
{
	bool left = false;
	int mid = n/2;
	int l = mid -1;
	int r = (n%2) ? mid + 1 : mid;
	while(l >= 0 && arr[l] == arr[r])
	{
		l--, r++;
	}
	if(l < 0 || arr[l] < arr[r])
	{
		left = true;
	}
	while(l >= 0)
	{
		arr[r] = arr[l];
		l--, r++;
	}
	if(left == true)
	{
		l = mid - 1;
		int carry = 1;
		if(n%2 == 1)
		{
			arr[mid] += carry;
			carry = arr[mid] /10;
			arr[mid]%=10;
			r = mid+1;
		}
		else
		{
			r = mid;
		}
		while(l >=0 )
		{
			arr[mid] += carry;
			carry = arr[mid] /10;
			arr[mid]%=10;
			arr[r] = arr[l];
			l--, r++;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

/*void next_no(int arr[], int n)
{
	
}*/

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	next(arr, n);
	return 0;
}
