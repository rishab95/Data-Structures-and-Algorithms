#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

void swap(char *a, char *b)
{
	char t = *a;
	*a = *b;
	*b = t;
}

void next(char num[], int n)
{
	int i, j;
	for(i=n-1;i>0;i--){
		if(num[i] > num[i-1]){
  			break;
  		}
	}
	if(i==0)
	{
		cout<<"No";
	}
	
	int p = num[i-1], small = i;
	for(j=i+1;j<n;j++)
	{
		if(num[j] > p && num[j] < num[small]){
			small = j;
		}
	}
	swap(&num[small], &num[i-1]);
	sort(num+i, num+n);
	cout<<num<<endl;
}

int main()
{
	char no[] = "4254";
	int n = strlen(no);
	next(no, n);
}
