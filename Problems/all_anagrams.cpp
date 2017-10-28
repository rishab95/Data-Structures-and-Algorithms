#include<iostream>
#include<algorithm>

using namespace std;
#define size 256
bool is_anagram(string s1, string s2)
{
	int count[size] = {0,};
	int i;
	for(i=0;s1[i] && s2[i];i++)
	{
		count[s1[i]]++;
		count[s2[i]]--;
	}
	if(s1[i] || s2[i])
	{
		return false;
	}
	for(i=0;i<size;i++)
	{
		if(count[i])
		{
			return false;
		}
	}
	return true;
}

void print(string arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(is_anagram(arr[i], arr[j]))
			{
				cout<<arr[i]<<" is of "<<arr[j]<<endl;
			}
		}
	}
}

int main()
{
	string arr[] = {"geeksquiz", "geeksforgeeks", "abcd","forgeeksgeeks", "zuiqkeegs"};
	int n  = sizeof(arr)/sizeof(arr[0]);
	print(arr, n);
	return 0;
}
