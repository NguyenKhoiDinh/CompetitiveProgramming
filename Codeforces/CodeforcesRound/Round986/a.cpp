#include <bits/stdc++.h>

using namespace std;

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    s += s;
    s += s;
    s += s;
    s += s;
    s += s; 
    s += s; 
    int x = 0, y = 0;
    bool ok = false; 
    for (int i = 0; i < (int) s.size(); i++) {
      if (x == a && y == b) {
        ok = true;
        break; 
      }
      if (s[i] == 'N') {
        y++;
      }
      else if (s[i] == 'E') {
        x++; 
      }
      else if (s[i] == 'S') {
        y--;
      }
      else {
        x--;
      }
    }
    cout << (ok == true ? "YES" : "NO") << endl;
  }
  return 0; 
}