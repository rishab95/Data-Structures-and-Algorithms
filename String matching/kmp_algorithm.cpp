//KMP Algorithm
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector <int> compute_failure_func(string pattern)
{
	int m = pattern.length();
	vector <int> func (m);
	func[0] = 0;

	int j = 0;
	for(int i=1;i<m;i++)
	{
		while(j >= 0 && pattern[j] != pattern[i])
		{
			if((j-1)>=0)
				j = func[j-1];
			else
				j = -1;
		}		
		j+=1;		
		func[i] = j;			
	}
	return func;
}

void kmp_search(string text, string pattern)
{
	vector <int> f = compute_failure_func(pattern);
	int pl = pattern.length();
	int tl = text.length();
	int j = 0;
	for(int i=0;i<tl;i++)
	{
		while(j>=0 && text[i] != pattern[j])
		{
			if((j-1)>=0)
				j = f[j-1];
			else
				j = -1;
		}		
		j+=1;		
		if(j == pl)
		{
			j = f[pl-1];
			cout<<i-pl+1;
		}
	}	
}

int main()
{
	string s = "ababaca";
	vector <int> m = compute_failure_func(s);
	for(int i=0;i<m.size();i++)
		cout<<m[i]<<" ";;
	cout<<endl;
	string t = "bacbabababacaab";
	kmp_search(t,s);	
	return 0;
}

