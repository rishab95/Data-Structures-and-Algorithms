#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job
{
	int start, finish; 
	int profit;	
};

bool jobComp(Job j1, Job j2)
{
	return (j1.finish < j2.finish);
}

int maxProfit(Job arr[], int n)
{
	sort(arr, arr+n, jobComp);
	int table[n];
	table[0] = arr[0].profit;

	for(int i=1;i<n;i++)
	{
		int inclProf = arr[i].profit;
		int l = i-1;
		for(l;l>=0;l--)
		{
			if(arr[l].finish <= arr[i].start)
			{
				inclProf += table[l];
			}
			table[i] = max(inclProf, table[i-l]);
		}
	}
	return table[n-1];
}

int main(int argc, char const *argv[])
{
	Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxProfit(arr, n)<<endl;
	return 0;
}
