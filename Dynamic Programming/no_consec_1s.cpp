#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int kingstreet(int m)
{
	int a[m], b[m];
	a[0] = b[0] = 1;
	for(int i=1;i<m;i++)
	{
		a[i] = a[i-1] + b[i-1];
		b[i] = a[i-1];
	}
	return (a[m-1] + b[m-1]);
}

int main()
{
	int m;
	cin>>m;
	int ans = 0;
	ans = kingstreet(m);
	cout<<(ans*ans)<<endl;
	return 0;
}

