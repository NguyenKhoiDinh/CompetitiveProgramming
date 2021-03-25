#include <bits/stdc++.h>

using namespace std;
int cnt[26];

class NearPalindromesDiv2 {
  public:
  string solve(string s) {
    string res = s;
    for (int i = 0; i < (int) s.size(); i++) {
      cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < (int) s.size(); i++) {
      if (cnt[s[i] - 'a'] % 2 == 1) {
        for (int c = 0; c < 26; c++) {
          if (cnt[c] % 2 == 1) {
            res[i] = (char) (c + 'a');
            cnt[c]++;
            cnt[s[i] - 'a']--;
          }
        }
      }
    }
    return res;
  }
};