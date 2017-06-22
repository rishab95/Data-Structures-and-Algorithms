#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void subsets(int S[], int n)
{
	int p_set = pow(2,n);

	//vector<vector<int>> result;

	for(int i=0;i<p_set;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i & (1<<j))
			{
				cout<<S[j]<<" ";
			}
		}
		cout<<endl;
	}
}

int main()
{
	int A[] = {1, 2, 3};
	subsets(A, 3) ;
	return 0;
}
