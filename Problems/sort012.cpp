#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
void sort012(int arr[], int n)
{
	int low = 0, high = n-1, mid = 0;
	while(mid <= high)
	{
		switch(arr[mid])
		{
			case 0: swap(&arr[low], &arr[mid]);
				 low++, mid++;
				 break;
		    case 1: mid++;
		    	 break;
		    case 2: swap(&arr[mid], &arr[high]);
		    	 high--;
		    	 break;
		}
	}
}
*/
int ans(int x, int n)
{
	if(n==0)
	{
		return 1;
	}
	int temp = ans(x,n/2);
	if(n%2 == 0)
	{
		return temp*temp;
	}
	else
	{
		return x*temp*temp;
	}
}

int check(int x, int y)
{
	if(x == 1)
 	{
 		return (y == 1);
 	}
 	
 	if(y % x == 0)
	 {
	 	return check(x, y/x);
	 }
	 if(y % x == 1)
 	 {
 	 	return 0;
 	 }
 	/*long long int p = 1;
 	while(p < y)
 	{
 		p = p*x;
 	}
 	return (p == y);*/
}

int is_pow(int a ,int b)
{
	if(a > 1)
	{
		while(x < y && y%x == 0)
		
	}
}


int main(int argc, char const *argv[])
{

	//cout<<ans(2, 3)<<endl;
	cout<<check(2, 4)<<endl;
	string T = "GEEGEEKS";
	//cout<<"Length is: "<<lps(T)<<endl;
	return 0;
}
