#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <string>

using namespace std;
int prime = 101;

long create_hash(string str, int len)
{
	long hash = 0;
	for(int i=0;i<=len;i++)
		hash += str[i]*pow(prime,i);
	return hash;
}

bool check_same(string str1, int s1, int e1, string str2, int s2, int e2)
{
	if((e1-s1) != (e2-s2))
	{
		return false;
	}
	while(s1 <= e1 && s2 <= e2)
	{
		if(str1[s1] != str2[s2])
		{
			return false;		
		}
		s1++;
		s2++;		
	}
	return true;
}

long recalculate_hash(string str, int oldindex, int newindex, long oldhash, int patternlen)
{
	long new_hash = oldhash - str[oldindex];
	new_hash = new_hash/prime;
	new_hash += str[newindex]*pow(prime,patternlen - 1);
	return new_hash;
}	

int rabin_karp_search(string text, string pattern)
{
	int m = pattern.length();
	int n = text.length();
	long patternhash = create_hash(pattern, m-1);
	long texthash = create_hash(text,m-1);
	for(int i = 1;i <= n-m+1; i++)
	{
		if(patternhash == texthash && check_same(text, i - 1,i + m - 2 ,pattern ,0 ,m - 1))
		{
			return i-1;
		}
		if(i < n - m + 1)
		{
			texthash = recalculate_hash(text,i-1,i+m-1,texthash,m);
		}
	}
	return -1;
}


int main(int argc, char const *argv[])
{
	string p1, t1, p2, t2;
	p1 = "abc";
	t1 = "abeabc";
	p2 = "ababaca";
	t2 = "bacbabababacaab";
	int x = rabin_karp_search(t1,p1);
	int y = rabin_karp_search(t2,p2);
	cout<<x<<endl<<y;
	return 0;
}
