#include<iostream>
#include<cstring>


using namespace std;

void seive(bool prime[], int n)
{
	for(int p=2;p*p<=n;p++)
	{
		if(prime[p] == false)
		{
			for(int i=p*2;i<=n;i+=p)
			{
				prime[i] = true;
			}
		}
	}
}

int ansdigit(int l, int r)
{
	bool prime[r+1];
	memset(prime, false, sizeof(prime));
	
	seive(prime, r);
	int fq[10] = {0};
	int val=0;
	for(int i=l;i<=r;i++)
	{
		if(!prime[i])
		{
			int x = i;
			while(x)
			{
				fq[x%10]++;
				x/=10;
			}
		}
	}
	
	int max = fq[0];
	for(int i=1;i<10;i++)
	{
		if(max <=fq[i])
		{
			max = fq[i];
			val = i;
		}
	}
	return val;	
}

int main()
{
	int a, b;
	cout<<"a: ";
	cin>>a;
	cout<<"b > a: ";
	cin>>b;
	cout<<ansdigit(a, b)<<endl;
	return 0;
}
