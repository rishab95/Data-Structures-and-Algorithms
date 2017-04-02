#include <iostream>
using namespace std;



int main()
{
	int ar[10],j ,n, tmp, m;
	cout<<"enter no"<<" ";
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin>>ar[i];
	}

	for(int i=0; i<n-1; i++)
	{
		m = i;
		for(int j = i+1; j<n; j++)
		{
			if(ar[j]<ar[m])
			{
				m = j;
			}
		tmp = ar[i];
		ar[i] = ar[m];
		ar[m] = tmp;
		}
	}

	cout<<"array"<<" ";
	for (int i = 0; i < n; ++i)
	{
		cout<<ar[i]<<" ";
	}

return 0;
}