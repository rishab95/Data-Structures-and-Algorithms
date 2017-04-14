#include <iostream>
#include <algorithm>

using namespace std;

int insert_bits(int n, int m, int i, int j)
{
	int all1s = ~0; // generate a sequence of all 1's;
	// 1s b4 pos j then 0s;
	int left = all1s << (j+1);

	//1's after i 
	int right = ((1 << i)) - 1;

	int mask = left | right; // bitwise ORing;

	int cleared_bits_n = n & mask;
	int shifted_bits_m = m << i; // to align hrough bits j (i to j);

	return shifted_bits_m | cleared_bits_n;
}

int main(int argc, char const *argv[])
{
	int n, m;
	int i, j;
	cout<<"n: ";
	cin>>n;
	cout<<"m: ";
	cin>>m;
	i = 2, j = 6;
	int x = insert_bits(n,m,i,j);
	cout<<x<<endl;
	return 0;
}
