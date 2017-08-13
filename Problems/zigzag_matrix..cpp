#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int m = 3, n = 4;
    int arr[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    int s = m*n;
    int ans[s];
    int i=0, j=0, k=0;
    ans[0]=arr[i][j];
    while(i<m-1 || j<n-1)
    {
        //forward
        if(j<n-1){
            j++;
            k++;
            ans[k]=arr[i][j];            
        }else if(i<m-1){
            i++;
            k++;
            ans[k]=arr[i][j];            
        }
        //diagonal down
        while(j>0 && i<m-1){
            i++;
            j--;
            k++;
            ans[k]=arr[i][j];            
        }
        if(i<m-1){
            i++;
            k++;
            ans[k]=arr[i][j];            
        }else if(j<n-1){
            j++;
            k++;
            ans[k]=arr[i][j];            
        }
        while(i>0 && j<n-1){
            i--;
            j++;
            k++;
            ans[k]=arr[i][j];            
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }            
        cout<<endl;
    }        
    for(int i=0;i<s;i++)
        cout<<ans[i]<<" ";
    return 0;        
}

