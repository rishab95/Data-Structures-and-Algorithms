#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

unsigned int swapEoBits(unsigned int n)
{
	unsigned int even_bits = n & 0xAAAAAAAA;
	unsigned int odd_bits = n & 0x55555555;

	even_bits = even_bits>>1;
	odd_bits = odd_bits<<1;

	return (even_bits | odd_bits);
}

int main(int argc, char const *argv[])
{
	/* code */
	int n;	
	cout<<"Enter n: ";
	cin>>n;	
	cout<<swapEoBits(n)<<" ";
	return 0;
}
