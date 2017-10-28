#include<iostream>
using namespace std;

int partition(int a[], int p, int r)
{
	int i, temp, x, j;
	i = p-1;
	x = a[r];
	cout<<x<<endl;
	for(j=p;j<=r-1;j++)
	{
		if(a[j]<=x)
		{
			i++;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	for(int k=0;k<=r;k++)
	{
		cout<<a[k]<<" ";
	}
	cout<<endl;
	temp = a[i+1];
	a[i+1] = a[r];
	a[r] = temp;
	return (i+1);
}

void quicksort(int a[], int p, int r)
{
	if(p < r)
	{
		int m = partition(a, p, r);
		quicksort(a, p, m-1);
		quicksort(a, m+1, r);
	}
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	quicksort(a, 0, n-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}	
	return 0;
}
