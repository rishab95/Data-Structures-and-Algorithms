#include <iostream>
#include <algorithm>

using namespace std;

bool isvowel(char c)
{
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int diff_str(string str)
{
	int count_vowels = 0, count_cons = 0;
	int consec_cons = 0, easy_words = 0, hard_words = 0;

	for(int i=0;i<str.length();i++)
	{
		if(str[i] != ' ' && isvowel(tolower(str[i])))
		{
			count_vowels++;
			consec_cons=0;
		}
		else if(str[i] != ' ')
		{
			count_cons++;
			consec_cons++;
		}
		if(consec_cons == 4)
		{
			hard_words++;
			while(i < str.length() && str[i] != ' ')
				i++;
			count_cons = 0;
			consec_cons = 0;
			count_vowels = 0;			
		}
		else if(i < str.length() && (str[i]==' ' || i == str.length() -1))
		{
			count_vowels > count_cons ? easy_words++ : hard_words++;
			count_cons = 0;
			consec_cons = 0;
			count_vowels = 0;			
		}
	}
	return 5*hard_words + 3*easy_words;
}

int main(int argc, char const *argv[])
{
	string s = "Welcome to microsoft";
	cout<<"difficulty: "<<diff_str(s)<<endl;
	return 0;
}

