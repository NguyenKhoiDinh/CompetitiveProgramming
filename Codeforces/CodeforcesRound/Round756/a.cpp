#include <bits/stdc++.h> 

using namespace std;
int numTest;

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    string s;
    cin >> s;
    bool found = false; 
    for (int i = 0; i < (int) s.size(); i++) {
      if ((s[i] - '0') % 2 == 0) {
        found = true; 
      }
    }
    if (found == false) {
      cout << -1 << endl;
      continue; 
    }
    if ((s.back() - '0') % 2 == 0) {
      cout << 0 << endl; 
    } 
    else if ((s[0] - '0') % 2 == 0) {
      cout << 1 << endl; 
    }
    else {
      cout << 2 << endl; 
    }
  }
  return 0; 
}