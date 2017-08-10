#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void permutate(vector<int> &arr, int s, vector<vector<int> > &ans)
{
	if(s == arr.size() - 1)
	{
		ans.push_back(arr);
		return ;
	}
	for(int i=s;i<arr.size(); i++)
	{
		swap(arr[s], arr[i]);
		permutate(arr, s + 1, ans);
		swap(arr[s], arr[i]); // backtrack;
	}
}

vector<vector<int> > sol(vector<int> &A)
{
	vector<vector<int> > ans;
	if(A.size() == 0)
		return ans;
	sort(A.begin(), A.end());

}

int int main(int argc, char const *argv[])
{

		
	return 0;
}
