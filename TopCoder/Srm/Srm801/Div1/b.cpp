#include <bits/stdc++.h>

using namespace std;

class EquivalentStrings {
  public:
  int count(vector <string> seeds) {
    set <string> ans;
    for (int i = 0; i < (int) seeds.size(); i++) {
      string s = seeds[i];
      for (int step = 1; step <= (int) s.size(); step++) {
        string collect = "";
        for (int d = '0'; d <= '8'; d++) {
          for (int j = 0; j < (int) s.size(); j++) {
            if (d == s[j] || d + 1 == s[j]) {
              collect += s[j];
            }
          }
          collect += '.';
        }
        ans.insert(collect);
        rotate(s.begin(), s.begin() + 1, s.end());
      }
    }
    return (int) ans.size();
  }
};

int main () {
  return 0;
}