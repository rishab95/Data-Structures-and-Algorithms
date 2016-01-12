#include <iostream>
using namespace std;

void merge(int *ar, int l, int m, int r)
{
	int left[m-l+1], right[r-m];

	for(int i=l;i<=m; i++)
	{	
		left[i-l] = *(ar+i);
	}
	for(int i=m+1; i<=r; i++)
	{
		right[i-m-1] = *(ar+i);
	}
	int i = 0, j = 0, k =l;    // i for left j for right k for ar


	while(i<(m-l+1) && j<(r-m))
	{
		if(left[i]<=right[j])
		{
			*(ar+k) = left[i];
			i++;
		}
		else
		{
			*(ar+k) = right[j];
			j++;
		}
	k++;
	}

	//Remainibg elements of left
	while(i<(m-l+1))
	{
		*(ar+k) = left[i];
		i++;
		k++;
	}

	while(j<(r-m))
	{
		*(ar+k) = right[j];
		j++;
		k++;
	}
}

void mergesort(int *ar, int l, int r)
{
	if(l<r)
	{
		int m = l+(r-l)/2;
		mergesort(ar, l, m);
		mergesort(ar, m+1, r);
		merge(ar, l, m, r);
	}
}

int main()
{
	int arr[] = {2,4,5,7,1,3,4,6};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	cout<<"Function \n";
	mergesort(arr, 0, arr_size - 1);
	cout<<"array"<<" ";
	for (int i = 0; i < arr_size; i++)
	{
		cout<<arr[i]<<" ";
	}
	/* code */
return 0;
}
