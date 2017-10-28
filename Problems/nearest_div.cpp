#include <bits/stdc++.h>
using namespace std;

int count_triplets(int n, int m)
{
	int a = n, b = m;	
	int x = a/b;
	int y1 = x*b;
	int y2 = (x+1)*b;
	int diff1 = abs(y1 - a), diff2 = abs(y2 - a);
	
	if(diff1 > diff2)
			 return y2;
    else if(diff1 <= diff2)
             return y1;		
}

int main()
{
	/*vector<int>arr;
	arr.push_back(1);
	arr.push_back(0);
	arr.push_back(0);
	arr.push_back(0);
	arr.push_back(1);
	arr.push_back(1); */
	//int p = 24;
	cout<<count_triplets(18, 7);
	return 0;
}	
