// Remove char from a string

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#define size 256
using namespace std;

int main()
{
	string a, b;
	getline(cin, a);
	getline(cin, b);
	int srci, desti;
	int hash[size];
	memset(hash, 0, sizeof(hash));

	while(b[srci])
	{
		hash[b[srci]] = 1;
		srci++;
	}
	srci = desti = 0;
	while(a[srci++])
	{
		if(!hash[a[srci]])
		{
			a[desti++] = a[srci];
		}
	}
	cout<<a<<endl;
	return 0;	
}
