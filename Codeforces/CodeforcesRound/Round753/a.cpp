#include <bits/stdc++.h> 

using namespace std;
int numTest;
string type, s; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> type >> s;
    int ans = 0;
    for (int i = 1; i < (int) s.size(); i++) {
      int prev = 0;
      int cur = 0;
      for (int j = 0; j < (int) type.size(); j++) {
        if (s[i - 1] == type[j]) {
          prev = j;
        }
        if (s[i] == type[j]) {
          cur = j;
        }
      }
      ans += abs(cur - prev);
    }
    cout << ans << endl; 
  }
  return 0; 
}