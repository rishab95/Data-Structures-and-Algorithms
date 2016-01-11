#include <iostream>
using namespace std;

int main()
{
	int a[10], n, tmp;
	cout<<"enter no";
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin>>a[i];
	}
	for (int i = 1; i <n; i++)
	{

		for(int j = 0; j <(n-i); j++)
		{
		if(a[j]>a[j+1])
			{
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}/* code */
	}
	cout<<"array";
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<endl;
	}
	/* code */
	return 0;
}

