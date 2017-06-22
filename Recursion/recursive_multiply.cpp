#include <iostream>
#include <algorithm>

using namespace std;

int multhelp(int s, int l)
{
	int res = 0;
	int x = s/2;
	for(int i=x; i>0;i--)
	{
		res = res + l;
	}

	if(s % 2 == 0)
	{
		res = 2*res;
		return res;
	}
	res = 2*res + l;
	return res;
}


int mult(int x, int y)
{
	if(x == 0 || y == 0)
		return 0;

	int s = x < y ? x : y;
	int l = x < y ? y : x;

	return multhelp(s, l);	
}


int main()
{
	int x, y;
	cout<<"x: ";
	cin>>x;
	cout<<"y: ";
	cin>>y;
	int ans = mult(x,y);
	cout<<ans;
}
