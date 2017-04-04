#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


int main() {
    stack <long long int> s1, s2;
    long int t;
    cin>>t;
    while(t--){
        int ch;
        cin>>ch;
        switch(ch){
            case 1:{ 
                    long long int x;
                    cin>>x;
                    s1.push(x);
                    break;
            }
            case 2:{
                    if(s2.empty()){
                        while(!s1.empty()){
                            s2.push(s1.top());
                            s1.pop();
                        }
                    }
                    s2.pop();
                    break;
            }
            case 3:{
                    if(!s2.empty()){
                        cout<<s2.top()<<endl;
                    }else{
                        while(!s1.empty()){
                            s2.push(s1.top());
                            s1.pop();
                        }
                        cout<<s2.top()<<endl;
                    }
                    break;
            }
        }
        
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
