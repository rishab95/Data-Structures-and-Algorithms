#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX 50
using namespace std;

long long int count(int s[],int n,int m)
    {
   long long int table[m+1][n+1];
    for(int i=0;i<=m;i++)
        {
        table[i][0]=1;
    }
    for(int j=0;j<=n;j++)
        {
        table[0][j]=0;
    }
    for(int i=1;i<=m;i++)
        {
        for(int j=1;j<=n;j++)
            {
            if(s[i-1]<=j)
                {
                table[i][j]=table[i-1][j]+table[i][j-s[i-1]];
            }
            else
                {
                table[i][j]=table[i-1][j];
            }
        }
    }
    return table[m][n];
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int S[MAX];
    int n,m;
    cin>>n>>m;    
    for(int i=0;i<m;i++){
        cin>>S[i];
    }
    cout<<count(S,n,m);
    
    return 0;
}
