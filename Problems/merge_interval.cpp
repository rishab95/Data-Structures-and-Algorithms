#include<iostream>
#include<algorithm>

using namespace std;

struct interval{
	int s, e;
};


bool comp(interval a, interval b)
{
	return a.s < b.s;
}

void merge_interval(interval arr[], int n)
{
	sort(arr, arr+n, comp);
	
	int ind = 0;
	for(int i=0;i<n;i++)
	{
		if(ind !=0 && arr[ind-1].e >= arr[ind].s)
		{
			while(ind !=0 && arr[ind-1].e >= arr[ind].s)
			{
				arr[ind-1].e = max(arr[ind-1].e, arr[ind].e);
				arr[ind-1].s = min(arr[ind-1].s, arr[ind].s);
				ind--;
			}
		}
		else
		{
			arr[ind] = arr[i];
		}
		ind++;
	}
	//cout << "\n The Merged Intervals are: ";
    for (int i = 0; i < ind; i++)
        cout << arr[i].s << " " << arr[i].e;
}

int main()
{
	interval arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} };
    int n = sizeof(arr)/sizeof(arr[0]);
    merge_interval(arr, n);
    return 0;
}

