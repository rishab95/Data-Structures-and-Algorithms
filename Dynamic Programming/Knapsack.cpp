#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int knapsack(vector<int> a, int n, int m){
    long long int t[n+1][m+1];
    for(int j=0;j<=m;j++){
        t[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        t[i][0]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(j>=a[i-1])
            {
                t[i][j]=max(a[i-1]+t[i][j-a[i-1]],t[i-1][j]);
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][m];
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector <int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        long long ans = knapsack(arr,n,k);
        cout<<ans<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

