#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void reverse_words(string &s, int i, int j)
{
	while(i < j){
		char a = s[i];
		s[i++] = s[j];
		s[j--] = a;
	}
}

void string_reverse(string &s)
{
	int i = 0, j = 0, p = 0;
	int slen = s.length();
	int words = 0;
	while(true)
	{
		while(i < slen && s[i] == ' ')
			i++;
		if(i == slen)
			break; //reached end of string

		if(words)
			s[j++] = ' ';

		p = j;
		while(i < slen && s[i] != ' ')
		{
			s[j] = s[i];
			i++, j++;
		}		
		reverse_words(s, p, j-1);
		words++;
	}
	reverse(s.begin(), s.end());
}

int main(int argc, char const *argv[])
{
	string s;
	s = "This is a national programming aptitude test by Google";
	string_reverse(s);
	cout<<s<<endl;
	return 0;
}