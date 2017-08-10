#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]){
	int t;
	cin>>t;
	while(t--){
		long long int a, b, count=0,flag=0;
		cin>>a>>b;
		if(b>a){
			a=a+b;
			b=a-b;
			a=a-b;		
		}
		while(a>0 || b>0){
			int carry = (a%10) + (b%10) + flag;
			a=a/10, b=b/10;
			if(carry/10 > 0){
				count++;
				flag=1;
			}else{
				flag=0;
			}			
		}
		cout<<count<<"\n";
	}
	return 0;
}
	