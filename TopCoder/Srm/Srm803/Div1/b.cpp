#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 3005;
int dp[MAX_N][(1 << 12) + 5];
vector <pair <char, int> > save;
int next[MAX_N][26];
pair <int, int> trace[MAX_N][(1 << 12) + 5];

void update(int &a, int b) {
  a = max(a, b);
}

class MarriageAndSelectionChallenge {
  public:
  string solve(string s) {
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
      for (int c = 0; c < 12; c++) {
        next[i][c] = -1;
      }
      for (int j = i + 1; j <= n; j++) {
        if (next[i][s[j - 1] - 'a'] == -1) {
          next[i][s[j - 1] - 'a'] = j;
        }
      }
    }
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
        for (int c = 0; c < 12; c++) {
          if (next[i][c] != -1) {
            int nextPos = next[i][c];
            if ((mask & (1 << c)) == 0) {
              if (dp[nextPos][mask | (1 << c)] < dp[i][mask] + 1) {
                dp[nextPos][mask | (1 << c)] = dp[i][mask] + 1;
                trace[nextPos][mask | (1 << c)] = make_pair(i, mask);
              }
              else if (dp[nextPos][mask | (1 << c)] == dp[i][mask] + 1) {
                if (s[trace[nextPos][mask | (1 << c)].first - 1] > s[i - 1]) {
                  trace[nextPos][mask | (1 << c)] = make_pair(i, mask);
                }
              }
            }
            else if (i > 0 && s[i - 1] - 'a' == c) {
              update(dp[nextPos][mask], dp[i][mask] + 1);
            }
          }
        }
      }
    }

  }
};

MarriageAndSelectionChallenge M;

int main () {
  cout << M.solve("cccaaccc");
  return 0;
}