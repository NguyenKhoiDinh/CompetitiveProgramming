#include <bits/stdc++.h>

using namespace std;
int numTest; 
int cnt[10005][26];

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    string s;
    cin >> s;
    string old = s;
    sort(s.begin(), s.end());
    bool found = false;
    do {
      bool check = true;
      for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == old[i]) {
          check = false;
          break;
        }
      }    
      if (check == true) {
        cout << s << endl;
        found = true;
        break;
      }
    }
    while (next_permutation(s.begin(), s.end()));
    if (found == false) {
      cout << "IMPOSSIBLE" << endl;
    }
  }
  return 0;
}