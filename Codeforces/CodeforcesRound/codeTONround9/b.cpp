#include <bits/stdc++.h>

using namespace std;

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    string s;
    cin >> s;
    int n = (int) s.size();
    if (n == 1) {
      cout << -1 << endl; 
    }  
    else {
      bool ok = false;
      for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
          cout << s[i] << s[i + 1] << endl;
          ok = true;
          break; 
        }
      }
      if (ok == false) {
        if (n == 2) {
          cout << -1 << endl; 
        }
        else {
          bool found = false;
          for (int i = 0; i < n - 2; i++) {
            if (s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i] != s[i + 2]) {
              cout << s[i] << s[i + 1] << s[i + 2] << endl;
              found = true;
              break;  
            }
          }
          if (found == false) {
            cout << -1 << endl;
          }
        }
      }
    }
  }
  return 0; 
}
     
