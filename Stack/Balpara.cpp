#include <iostream>
#include <string>
#include <stack>
using namespace std;
//int size = 100;
//int top = -1;
//last  opened cloaed first
//scsan from l to r
bool arepair(char open, char close);
bool balpara(string s);

int main()
{
	//stack s1;
	string exp;
	cout<<"Enter exp : ";
	cin>>exp;
	if(balpara(exp))
		cout<<"Balanced\n";
	else
		cout<<"Not Balanced\n";
	return 0;
}

bool arepair(char open, char close)
{
	if(open == '(' && close == ')')
		return true;
	else if(open == '{' && close == '}')
		return true;
	else if(open == '[' && close == ']')
		return true;
	else 
		return false;	
}

bool balpara(string str)
{
	stack<int> s1;
	for(int i=0;i<str.length();i++)
	{
		if(str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			s1.push(str[i]);
		}
		else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			if(s1.empty() || !arepair(s1.top(), str[i]))
				return false;
			else 
				s1.pop();
		}
	}
	return s1.empty() ? true : false;
}

