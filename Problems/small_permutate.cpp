#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(int a, int b)
{
	return a > b;
}

vector<int> bitonic(vector<int> &arr, int k)
{
	int n = arr.size();
	sort(arr.begin(), arr.begin() + k);
	sort(arr.begin() + k, arr.end(), comp);
	
	return arr;
}


string small(string s)
{
	int n = s.size();
	sort(s.begin(), s.end());
	cout<<s<<endl;
	int i = 0;
	while(s[i] == '0')
	    i++;
	swap(s[0], s[i]);
	return s;
	
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        //long long int n;
        
        string n;
        cin>>n;
        cout<<small(n);
        cout<<endl;
    }
	return 0;
}
/*
int main()
{
	long long int n;
	//cout<<"Enter n: ";
	//cin>>n;
	//cout<<"Ans: "<<small(n)<<endl;
	vector<int> arr;
	arr.push_back(5);
	arr.push_back(4);
	arr.push_back(3);
	arr.push_back(2);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(5);
	arr.push_back(6);
	vector<int> res = bitonic(arr, 5);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<" ";
	}
	return 0;
}*/

