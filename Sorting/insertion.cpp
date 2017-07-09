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
		j = i;
		while(j > 0 && a[j-1] > tmp)
		{
			a[j] = a[j-1];
			j--;
		}
		a[j] = tmp;
	}
	for (int i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
}