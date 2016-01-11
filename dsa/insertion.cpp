#include <iostream> 
using namespace std;

int main()
{
	int a[10], j, n , tmp;
	cin>>n;

	for(int i = 0;i < n;i++)
	{
			cin>>a[i];
	}
	for(int i = 1;i < n;i++)
	{
		tmp = a[i];
		j = i-1;

		while(j>=0 && a[j]>tmp)
		{
			a[j+1] = a[j];
			j = j-1;
		}
		a[j+1] = tmp;
	}
	for (int i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
}		
