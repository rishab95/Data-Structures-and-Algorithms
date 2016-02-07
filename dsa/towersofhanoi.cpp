#include <iostream>
using namespace std;

void movefrom(int from, int to)
{
	cout<<"\n Move disk 1 from rod "<<from<<"to rod "<<to;
}

void towersofhanoi(int n, char from, char to, char aux)
{
	if(n == 1)
	{
		movefrom(from, to);
	}
	else
	{
		towersofhanoi(n-1, from, aux, aux);
		towersofhanoi(1, from, to, aux);
		towersofhanoi(n-1, aux, to, aux);
	}
}

int main()
{
	int n;
	cin>>n;
	towersofhanoi(n, 1, 3, 2);
	return 0;
} 
