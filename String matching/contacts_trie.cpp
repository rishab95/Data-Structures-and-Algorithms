#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

struct node {
    node * children[26] = {NULL};
    int count = 0;
};

void addnode (node* root, string name, int cur) {
    root -> count += 1;
    if (cur == name.size()) return;
    if (!root -> children[name[cur] - 'a']) 
      root -> children[name[cur] - 'a'] = new node();
    addnode(root -> children[name[cur]- 'a'], name, cur + 1);
}

int findnode(node * root, string name, int cur) {
    if (cur == name.size()) {
        return root -> count;
    }
    else if (!root -> children[name[cur] - 'a']) {
        return 0;
    }
    else {
        return findnode(root -> children[name[cur] - 'a'], name, cur + 1);
    }
}

int main() {   
    int n;
    cin >> n;
    string a, b;
    unordered_set<string> s;
    node * root = new node();
    for (int i = 0; i < n; i++) {
        cin >> a >> b;        
        if (a == "add") {
            if (s.find(b) == s.end()) {
                s.insert(b);
                addnode(root, b, 0);
            }
        }       
        else if (a == "find") {
            cout << findnode(root, b, 0) << endl;
        }
    }
    return 0;
}


// Map of all Substrings of the input string
/*std::map<string, long int> contactsMap;

void addContacts(string contactName){
  for (size_t i = 1; i <= contactName.size(); i++) {
    std::string subStr = contactName.substr(0,i);
    if (contactsMap.find(subStr) != contactsMap.end() ) { // Existing Entry
      contactsMap[subStr]+=1;
    }
    else{
      contactsMap[subStr]=1; // New Entry
    }
  }
}

long int extractContacts(string contactName){
  if (contactsMap.find(contactName) != contactsMap.end()) { //Entry Found
    std::map<string, long int>:: iterator contactsIter  = contactsMap.find(contactName);
    return contactsIter->second;
  }
  else{
    return 0; // No Entry Found
  }
}

int main() {

  long int querySize;
  std::cin >> querySize;
  for (size_t i = 0; i < querySize; i++) {
    string opName,inputString;
    std::cin >> opName>>inputString;
    if (opName=="add") {
      addContacts(inputString);
    }
    else if(opName=="find"){
    std::cout <<  extractContacts(inputString) << '\n';
    }
  }
    return 0;
} */
