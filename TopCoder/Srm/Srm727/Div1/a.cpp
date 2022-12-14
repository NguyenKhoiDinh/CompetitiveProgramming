#include <bits/stdc++.h>

using namespace std;

class OnlySanta {
  public:
  string solve(string S) {
    int pos = -1;
    int n = (int) S.size();
    for (int i = n - 1; i >= 0; i--) {
      if (S[i] == 'N') {
        pos = i;
        break;
      }
    }
    string ans = "";
    if (pos == -1) {
      ans = "SANTA";
      ans += S;
    }
    else {
      string ss = "SAT";
      int curPos = 0;
      for (int i = 0; i < pos; i++) {
        if (curPos < 3 && S[i] == ss[curPos]) {
          curPos++;
        }
      }
      if (curPos == 3) {
        ans = S;
        ans += "TA";
      }
      else {
        for (int i = 0; i < pos; i++) {
          ans += S[i];
        }
        ans += "SA";
        for (int i = pos; i < n; i++) {
          ans += S[i];
        }
        ans += "TA";
      }
    }
    return ans;
  }
};

int main () {
  return 0;
}