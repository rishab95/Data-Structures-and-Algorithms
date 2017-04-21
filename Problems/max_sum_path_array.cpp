/*

The idea is to do something similar to merge process of merge sort. We need to calculate sums of elements between all common points for both arrays. Whenever we see a common point, we compare the two sums and add the maximum of two to the result. Following are detailed steps.

1) Initialize result as 0. Also initialize two variables sum1 and sum2 as 0. Here sum1 and sum2 are used to store sum of element in ar1[] and ar2[] respectively. These sums are between two common points.

2) Now run a loop to traverse elements of both arrays. While traversing compare current elements of ar1[] and ar2[].

    2.a) If current element of ar1[] is smaller than current element of ar2[], then update sum1, else if current element of ar2[] is smaller, then update sum2.

    2.b) If current element of ar1[] and ar2[] are same, then take the maximum of sum1 and sum2 and add it to the result. Also add the common element to the result.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	int n , m;
	cout<<"n: ";
	cin>>n;
	cout<<"m: ";
	cin>>m;
	vector <int> a(n);
	vector <int> b(m);
	for (int i = 0; i < n; ++i)
		cin>>a[i];
	for (int i = 0; i < m; ++i)
		cin>>b[i];

	int x = 0, y = 0, sum = 0;
	int i = 0, j = 0;
	while(i < n && j < m)
	{
		int c = a[i];
		int d = b[j];
		if(c == d)
		{
			sum += c + max(x,y);
			x = 0;
			y = 0;
			i++, j++;
			continue;
		}

		if(c < d)
		{
			x = x + c;
			i++;
		}
		else
		{
			y = y + d;
			j++;
		}
	}
	
}
