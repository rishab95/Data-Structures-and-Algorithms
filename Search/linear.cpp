#include <iostream>
using namespace std;

void linearSearch(int ar[], int n, int e)
{
	
	for(int i=0;i<n;i++)
	{
		if(ar[i] == e)
			cout<<e; 
	}
}

int main()
{
	int arr[] = {1,2,3,4,5};
	int as = sizeof(arr)/sizeof(arr[0]);
	linearSearch(arr, as, 0);

return 0;
}