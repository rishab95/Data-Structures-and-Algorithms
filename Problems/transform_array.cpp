#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> trans(vector<int> a)
{
	int t;
	for(int i=0;i<a.size();)
	{
		if(a[i] == 0)
		{
			i++;
			continue;
		}
		int j;
		for(j=i+1;j<a.size();j++)
			if(a[j] != 0)
				break;
		if(j < a.size() && a[i] == a[j])
		{
			a[i] = 2*a[i];
			a[j] = 0;
		}
		else
		{
			i++;
		}
	}	 
	return a;
}


int main(int argc, char const *argv[])
{
	int n;
	vector<int> a;	
	cin>>n;
	a.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int ct = 0;
	a = trans(a);		
	for(int i=0;i<a.size();i++)
	{
		if(a[i] != 0)
			cout<<a[i]<<" ";
		else if(a[i] == 0)
			ct++;
	}
	while(ct)
	{
		cout<<"0"<<" ";
		ct--;
	}
	cout<<endl;
	return 0;
}
