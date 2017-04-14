#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	int n, m;
	cout<<"n: ";
	cin>>n;
	cout<<"m: ";
	cin>>m;
	vector <int> a(n);
	vector <int> b(m);
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int j=0;j<m;j++)
		cin>>b[j];

	n = a.size()-1, m = b.size()-1;
	int f = a.size() + b.size() -1;
	int s = f;
	while(m >= 0)	
	{
		if(n >= 0 && a[n] > b[m])
		{
			a[f] = a[n];
			n--;
		}
		else
		{
			a[f] = b[m];
			m--;
		}
		f--;
	}

	//sorted_array_merge(a,b);
	for(int i=0;i<=s;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
