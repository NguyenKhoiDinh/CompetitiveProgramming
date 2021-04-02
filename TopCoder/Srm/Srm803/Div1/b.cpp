#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 3005;
int dp[MAX_N][(1 << 12) + 5];
vector <pair <char, int> > save;

void update(int &a, int b) {
  a = max(a, b);
}

class MarriageAndSelectionChallenge {
  public:
  string solve(string s) {
    int n = (int) s.size();
    int maxi = -1;
    string ans = "";
    for (char c = 'a'; c <= 'l'; c++) {
      string tmp = "";
      for (int i = 0; i < n; i++) {
        if (s[i] == c) {
          cnt++;
          tmp += s[i];
        }
      }
      if (maxi < (int) tmp.size()) {
        maxi = (int) tmp.size();
        ans = tmp;
      }
    }
    s += '.';
    int len = 1;
    for (int i = 1; i <= n; i++) {
      if (s[i] != s[i - 1]) {
        save.push_back(make_pair(s[i - 1], len));
        len = 1;
      }
      else {
        len++;
      }
    }
    n = (int) save.size();
    for (int i = 0; i <= n; i++) {
      for (int mask = 0; mask < (1 << 12); mask++) {
        dp[i][mask] = -1;
      }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int mask = 0; mask < (1 << 12); mask++) {
        if (dp[i][mask] == -1) {
          continue;
        }
        update(dp[i + 1][mask], dp[i][mask]);
        int nxtChar = save[i].first - 'a';
        if ((mask & (1 << nxtChar)) == 0) {
          update(dp[i + 1][mask | (1 << nxtChar)], dp[i][mask] + save[i].second);
        }
      }
    }
    return ans;
  }
};

MarriageAndSelectionChallenge M;

int main () {
  cout << M.solve("cccaaccc");
  return 0;
}