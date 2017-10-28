#include<bits/stdc++.h>
using namespace std;

bool p[100][100];
void palin(int n,string str)
{
    int i,d,j;
    for(i=0;i<n;i++)
    	p[i][i]=1;
    for(d=2;d<=n;d++)
    {
        for(i=0;i<=n-d;i++)
        {
            j=i+d-1;
            if(d==2)
            {
                if(str[i]==str[j])
                	p[i][j]=1;
                else
                	p[i][j]=0;
            }
            else if(str[i]==str[j]&&p[i+1][j-1])
            	p[i][j]=1;
            else
            	p[i][j]=0;
        }
    }
}
void allpart(string str,int n,int j,vector<string> &v)
{   int k;
    if(j==n)
    {
        for(k=0;k<v.size();k++)
        	cout<<v[k]<<" ";
        cout<<"\n";
        return;
    }
    
    for(k=j;k<n;k++)
        {
            if(p[j][k])
            {
                v.push_back(string(str.begin()+j,str.begin()+k+1));
                allpart(str,n,k+1,v);
                v.pop_back();
            }
       }
}

int main()
{
	string str = "nitin";
	int n=str.size();
	p[100][100]={0};
	vector<string> v;
	palin(n,str);
	allpart(str,n,0,v);
	return 0;
}