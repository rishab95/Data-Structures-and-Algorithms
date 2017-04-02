#include <iostream>
using namespace std;

int main()
{
	int ar[10],j ,n, tmp, gap;
	cout<<"enter no"<<" ";
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin>>ar[i];
	}
	for(int gap=n/2; gap>0; gap/=2)
	{
		for(int i=gap; i<n; i++)
		{
			tmp = ar[i];
			for(j=i; j>=gap && ar[j-gap]>tmp; j-=gap)
			{
				ar[j] = ar[j-gap];
			}
		ar[j] = tmp;
		}
	}

	cout<<"array"<<" ";
	for (int i = 0; i < n; ++i)
	{
		cout<<ar[i]<<" ";
	}
	/* code */

return 0;
}