#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool is_palin(string str, int s, int e)
{
	while(s < e)
	{
		if(str[s] != str[e])
			return false;
		s++;
		e--;
	}
	return true;
}

int min_insert(string str)
{
	int n = str.size();
	for(int i=n-1;i>=0;i--)
	{
		if(is_palin(str, 0, i))
			return (n-i-1);
	}	
}

int main()
{
	string str;
	getline(cin, str);
	cout<<"Min count is: "<<min_insert(str)<<endl;
	return 0;
}
