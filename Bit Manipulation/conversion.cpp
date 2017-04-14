#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int result(int a, int b)
{
	int ans = 0;
	for(int i = a ^ b ; i != 0; i = i & (i-1))
	{
		ans++;
	}
	return ans;
}

int main()
{
	int x, y;
	cin>>x>>y;
	int res = result(x,y);
	cout<<res<<endl;
}


