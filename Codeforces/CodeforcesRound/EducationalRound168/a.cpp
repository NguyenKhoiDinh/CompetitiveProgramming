#include <bits/stdc++.h>

using namespace std;

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    string s;
    cin >> s;
    bool ok = false; 
    string st = ""; 
    for (int i = 0; i < (int) s.size(); i++) {
      if (i > 0 && s[i] == s[i - 1] && ok == false) {
        ok = true;
        st += (char) ((s[i] - 'a' + 1) % 26 + 'a');   
      }
      st += s[i]; 
    } 
    if (ok == false) {
      st += (char) ((s.back() - 'a' + 1) % 26 + 'a'); 
    }
    cout << st << endl;
  }
  return 0; 
}