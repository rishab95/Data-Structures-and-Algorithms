#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	int dir;
	// 0 - r 1 - d 2 - l 3 - t;
	int T = 0, B = n-1, L = 0, R = n-1;
	dir=0;
	while(T <= B && L <= R)
	{
		if(dir == 0)
		{
			for(int i=L;i<=R;i++)
				cout<<arr[T][i]<<" ";
			T++;
			dir=1;
		}
		else if(dir == 1)
		{
			for(int i=T;i<=B;i++)
				cout<<arr[i][R]<<" ";
			R--;
			dir = 2;
		}
		else if(dir == 2)
		{
			for(int i=R;i>=L;i--)
				cout<<arr[B][i]<<" ";
			B--;
			dir = 3;
		}
		else
		{
			for(int i=B;i>=T;i--)
				cout<<arr[i][L]<<" ";
			L++;
			dir = 0;
		}
	}
	return 0;
}