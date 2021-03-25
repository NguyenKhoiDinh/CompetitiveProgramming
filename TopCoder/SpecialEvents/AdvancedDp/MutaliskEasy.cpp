#include <bits/stdc++.h>

using namespace std;
const int MAX_V = 63;
const int inf = 1000005;
int dp[MAX_V][MAX_V][MAX_V];

int getVal(int x) {
  if (x == 0) {
    return 9;
  }
  else if (x == 1) {
    return 3;
  }
  else {
    return 1;
  }
}

class MutaliskEasy {
  public:
  int minimalAttacks(vector <int> HP) {
    while ((int) HP.size() < 3) {
      HP.push_back(0);
    }
    for (int a = 0; a < MAX_V; a++) {
      for (int b = 0; b < MAX_V; b++) {
        for (int c = 0; c < MAX_V; c++) {
          dp[a][b][c] = inf;
        }
      }
    }
    dp[HP[0]][HP[1]][HP[2]] = 0;
    for (int a = HP[0]; a >= 0; a--) {
      for (int b = HP[1]; b >= 0; b--) {
        for (int c = HP[2]; c >= 0; c--) {
          vector <int> p = {0, 1, 2};
          do {
            int nxta = max(0, a - getVal(p[0]));
            int nxtb = max(0, b - getVal(p[1]));
            int nxtc = max(0, c - getVal(p[2]));
            dp[nxta][nxtb][nxtc] = min(dp[nxta][nxtb][nxtc], dp[a][b][c] + 1);
          }
          while (next_permutation(p.begin(), p.end()));
        }
      }
    }
    return dp[0][0][0];
  }
};

MutaliskEasy M;

int main () {
  cout << M.minimalAttacks({54,18,6});
  return 0;
}