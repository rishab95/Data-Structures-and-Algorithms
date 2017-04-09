#include <iostream>
#include <string>
using namespace std;
int size = 100;
int top = -1;
//last  opened cloaed first
//scsan from l to r
bool arepair(char open, char close);
bool balpara();
class stack
{
	
	int s[100];
	public:
		void push(int); 
		void pop(); 
		void top(); 
		void empty(); 
		void show(); 
};

void stack::push(int x)
{
	if(top < size)
		s[top++] = x;
	else
		cout<<"Stack is full\n";
}

void stack::pop()
{
	if(top>=0)
		top--;
	else
		cout<<"Stack is empty\n";
}

void stack::top()
{
	if(top>=0)
		cout<<s[top]<<endl;
}

void stack::empty()
{
	if(top<0)
		cout<<"stack is empty\n";
}

int main()
{
	stack s1;
	string exp;
	cout<<"Enter exp : ";
	cin>>exp;
	if(balpara(exp))
		cout<<"Balanced\n";
	else
		cout<<"Not Balanced\n"
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
	for(int i=0;i<str.length();i++)
	{
		if(str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			s1.push(str[i]);
		}
		else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			if(s1.empty || !arepair(s1.top, str[i]))
				return false;
			else 
				return s1.pop();
		}
	}
	return s1.empty() ? true : false;
}
