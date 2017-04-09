#include <iostream>
using namespace std;
#define size  50;
int top = -1;
//last  opened cloaed first
//scsan from l to r
bool arepair(char open, char close);
bool balpara();
class stack
{
	int s[50];
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
		s[++top] = x;
	else
		cout<<"Stack is full\n";
}

void stack::pop()
{
	if(top>=0)
		top--;
	else
		cout<<"Stack is empty\n"''
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

}
