#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;

void reverse_words(string &s, int i, int j)
{
	while(i < j){
		char a = s[i];
		s[i++] = s[j];
		s[j--] = a;
	}
}
int main() {	
    string s;
    getline(cin, s);  
    int j=0, i=0;
    for(i=0;i<s.length();i++)
    {
        if(s[i] ==' ')
        {
            //reverse_words(s, j, i-1);
            reverse(s.begin()+j,s.begin()+i);
            s[j] = toupper(s[j]);
            j = i+1;
        }
        
    }
    reverse_words(s, j, i-1);        
    s[j] = toupper(s[j]);
    cout<<s<<endl; 
    return 0;
}
