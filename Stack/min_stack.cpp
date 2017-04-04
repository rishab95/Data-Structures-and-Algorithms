#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <iterator>    


stack <int> s1, s2;

void push(int x) {
    s1.push(x);
    if (s2.empty() || x <= getMin())  s2.push(x);	    
}
void pop() {
    if (s1.top() == getMin())  s2.pop();
    s1.pop();
}
int top() {
    return s1.top();
}
int getMin() {
    return s2.top();
}

int main(){
    push(5);
    push(7);
    push(11);
    cout<<getMin()<<"\n";
    push(3);
    pop();
    push(9);
    push(4);
    cout<<top<<"\n";    
}