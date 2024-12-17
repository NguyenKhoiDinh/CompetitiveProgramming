#include <bits/stdc++.h>

using namespace std;
int numTest; 
int n, a, b;
string s; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> a >> b;
    cin >> s;     
    if (a == b) {
      for (int i = 0; i + a - 1 < n; i++) {
        if (s[i] == '0') {
          for (int j = i; j <= i + a - 1; j++) {
            if (s[j] == '0') {
              s[j] = '1';
            }
            else {
              s[j] = '0'; 
            }
          }
        }
      }
      bool ok = true; 
      for (int j = 0; j < n; j++) {
        if (s[j] != '1') {
          ok = false;
          break;
        }
      }
      cout << (ok == true ? "YES" : "NO") << endl;
      continue;
    }
    if (2 * a <= n) {
      cout << "YES" << endl;
      continue; 
    }
    bool ok = true; 
    for (int i = n - a + 1; i < a; i++) {
      if (s[i] == s[i - 1]) {
        continue; 
      }
      ok = false;
      break;
    }
    cout << (ok == true ? "YES" : "NO") << endl;
  }
  return 0; 
}