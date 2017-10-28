#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
void reverse_words(string &s, int i, int j);
/*
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
}*/

void string_reverse(string &str)
{
	int ws, we, len;
	len = str.length();
	reverse_words(str, 0, len-1);
	for(ws = we = 0; we < len; we++)
	{
		if(str[we] != '.')
		{
			ws = we;
			while(str[we] != '.' && we < len)
			{
				we++;
			}
			we--;
			reverse_words(str, ws ,we);
		}
	}
	//return str;
}
void reverse_words(string &s, int i, int j)
{
	while(i < j){
		char a = s[i];
		s[i++] = s[j];
		s[j--] = a;
	}
}

int main(int argc, char const *argv[])
{
	string s;
	//s = "This is a national programming aptitude test by Google";
	getline(cin, s);
	string_reverse(s);//<<endl;
	cout<<s<<endl;
	return 0;
}
//#include<bits/stdc++.h>

//using namespace std;
/*
void reverse_words(string &s, int i, int j)
{
	while(i < j){
		char a = s[i];
		s[i++] = s[j];
		s[j--] = a;
	}
}
void string_reverse(string &str)
{
	int ws, we, len;
	len = str.length();
	reverse_words(str, 0, len-1);
	for(ws = we = 0; we < len; we++)
	{
		if(str[we] != '.')
		{
			ws = we;
			while(str[we] != '.' && we < len)
			{
				we++;
			}
			we--;
			reverse_words(str, ws ,we);
		}
	}
	//return str;
}
int main()
{
    int t;
    //cin>>t;
    string s;
    
    getline(cin, s);
    string_reverse(s);
    cout<<s<<endl;        
    
	return 0;
}*/



