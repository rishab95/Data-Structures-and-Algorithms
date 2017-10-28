#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cycle_len[] = {4,4,2,1,1,4,4,2}; // 2 4 5 6 7 8 9 
vector<vector<int> > cycles;


int main()
{
	for(int i=2;i<=9;i++)
	{
		int a = i;
		vector<int> cycle;
		for(int j=0;j<cycle_len[i-2];j++)
		{
			cycle.push_back(a%10);
			a = a*i;
		}
		cycles.push_back(cycle);
		cycle.clear();
	}

	int t;
	cin>>t;
	while(t--)
	{
		string a, b;
		cin>>a>>b;
		//getline(cin, a);
		//getline(cin, b);
		int x = (a[a.size()-1] - '0');
		int y = (b[b.size()-1] - '0');
		if(x >=0 && x<=9 && y>=0 && y<=9)
		{
			x = x%10;
			//b = b%10;
			if(x == 1 || y == 0)
				cout<<x<<endl;
			else if(x == 0)
				cout<<'0'<<endl;
			else
			{
				y = (y-1)%cycle_len[x-2];
				cout<<"b: "<<b<<endl;
				cout<<cycles[x-2][y]<<endl;
			}
		}
		else
		{
			cout<<"invalid\n";
		}
	}
	return 0;
}


