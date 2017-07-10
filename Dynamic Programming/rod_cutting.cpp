#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int cut_rod(vector<int> price)
{
	int length = price.size();
	int value[length+1];
	value[0]=0;
	for(int i=1;i<=length;i++)
	{
		int max_val = INT_MIN;	
		for(int j=0;j<i;j++)
		{
			max_val = max(max_val, price[j] + value[i-j-1]);
		}
		value[i] = max_val;
	}
	return value[length];
}

int main(int argc, char const *argv[])
{
	vector<int> price;
	price.push_back(11);
	price.push_back(25);
	price.push_back(81);
	price.push_back(19);
	price.push_back(13);
	price.push_back(17);
	price.push_back(27);
	price.push_back(20);	
	int ans = cut_rod(price);
	cout<<"Ans: "<<ans<<"\n";
	return 0;
}
