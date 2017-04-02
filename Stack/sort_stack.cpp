#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

void sort_stack(stack <int> s1)
{
	stack <int> s2;
	while(!s1.empty())
	{
		int t = s1.top();
		s1.pop();
		while(!s2.empty() && s2.top() < t)
		{
			s1.push(s2.top());
			s2.pop();
		}
		s2.push(t);
	}

	while(!s2.empty())
	{
		cout<<s2.top()<<" ";
		s2.pop();
	}
}

int main(){
	stack <int> s1;
	s1.push(9);
	s1.push(5);
	s1.push(4);
	s1.push(6);
	s1.push(10);
	s1.push(7);
	s1.push(2);
	sort_stack(s1);
}