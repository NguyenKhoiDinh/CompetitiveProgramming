#include <bits/stdc++.h>

using namespace std;

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    string s;
    cin >> n >> s;
    int m = n;
    n *= 4;
    vector <int> cnt(4, 0);
    int mark = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != '?') {
        cnt[s[i] - 'A']++; 
      }
      else {
        mark++; 
      }
    }  
    int ans = 0;
    for (int i = 0; i < 4; i++) {
      ans += min(m, cnt[i]); 
      cnt[i] = max(0, m - cnt[i]); 
    }
    cout << ans << endl;
  }
  return 0; 
}