#include <iostream>
#include <algorithm>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

int my_atoi(string &s) {
    int res = 0;
    int sign = 1;    
    int i = 0;
    if (s[0] == '-'){
        sign = -1;
        i++; 
    }
    for(;s[i]!='\0';i++)
    {
        int t = s[i] - '0';

        if(t>=0 && t<=9){
            res = res*10 + t;            
        }
        else{            
            return -1; //Inavlid string.
        }        
    }
    return res*sign;
}

int main(int argc, char const *argv[])
{
    /* code */
    string s = "-123";
    cin>>s;
    cout<<my_atoi(s)<<"\n";
    return 0;
}
