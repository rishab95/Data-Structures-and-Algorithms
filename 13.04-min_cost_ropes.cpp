#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int arr[n];
    	for(int i=0;i<n;i++)
    	{
    		cin>>arr[i];
    	}
    	priority_queue <int, vector <int> , greater <int> > mpq(arr, arr+n);
    	int sum = 0;
    	while(mpq.size() > 1)
    	{
    		int f = mpq.top();
    		mpq.pop();
    		int s = mpq.top();
    		mpq.pop();
    
    		sum += (f + s);
    		mpq.push(f+s);
    
    	}
    	cout<<sum<<"\n";
    }
	return 0;
}
