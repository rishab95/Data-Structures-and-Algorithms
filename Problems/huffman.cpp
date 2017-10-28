
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;
void decode_huff(node * root,string s)
{
    node* temp = root;
    for (char c : s) {
        temp = c == '0' ? temp->left : temp->right;
        if (temp->data) {
            cout << temp->data;
            temp = root;
        }
    }
}


for (int i=0;i<n;++i){
    if (B[i]=='0' &&  B[i+1]=='1' && B[i+2]=='0'){
         ++step;
        i +=2;
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
