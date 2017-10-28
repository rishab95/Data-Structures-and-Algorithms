#include<iostream>

using namespace std;

int main()
{
	int a, b, c;
	cin>>a>>b>>c;
	if(a+c == 2*b)
	{
		cout<<"AP\n";
		int d = b-a;
		cout<<c+d<<endl;
	}
	else if((c*a)%b == 0)
	{
		cout<<"GP\n";
		int r = b/a;
		cout<<c*r<<endl;
	}
	else
	{
		cout<<"NO\n";
	}
		
	return 0;
}
