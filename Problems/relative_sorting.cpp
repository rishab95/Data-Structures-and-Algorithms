#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)	{
		int n, m;
		cin>>n>>m;
		vector<int> a(n), b(m), res(n);
		int k=0;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<m;i++)
			cin>>b[i];
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(b[i] == a[j]){
					res[k] = a=[j];	
					a[j] = -1;
					k++;
				}
			}
		}			
		sort(a.begin(),a.end());
		for(int i=0;i<n;i++){
			if(a[i] != -1){
				res[k] = a[i];
				k++;
			}
		}
		for(int i=0;i<n;i++)
	    	cout<<result[i]<<" ";
	    cout<<endl;
	}	
	return 0;
}
