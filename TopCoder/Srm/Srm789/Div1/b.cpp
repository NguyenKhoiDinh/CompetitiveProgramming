#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 205;
const int MOD = 1000000007;
vector <int> listState;
vector <int> nextState[MAX_N][MAX_N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int state[3][15];
int dp[2][MAX_N][MAX_N][MAX_N];

void update(int &a, int b) {
  (a += b) %= MOD;
}

class BasePlacement {
  public:
  int count(int R, int C, int B) {
    if (R < C) {
      swap(R, C);
    }
    for (int mask = 0; mask < (1 << C); mask++) {
      bool check = true;
      for (int i = 0; i < C - 1; i++) {
        if (((mask & (1 << i)) > 0) && ((mask & (1 << (i + 1))) > 0)) {
          check = false;
          break;
        }
      }
      for (int i = 1; i < C - 1; i++) {
        if (((mask & (1 << (i + 1))) > 0) && ((mask & (1 << (i - 1))) > 0)) {
          check = false;
          break;
        }
      }
      if (check == true) {
        listState.push_back(mask);
      }
    }
    for (int i = 0; i < (int) listState.size(); i++) {
      for (int j = 0; j < (int) listState.size(); j++) {
        for (int k = 0; k < (int) listState.size(); k++) {
          vector <int> saveState;
          saveState.push_back(listState[i]);
          saveState.push_back(listState[j]);
          saveState.push_back(listState[k]);
          for (int r = 0; r <= 2; r++) {
            for (int c = 0; c < C; c++) {
              if ((saveState[r] & (1 << c)) > 0) {
                state[r][c] = 1;
              }
              else {
                state[r][c] = 0;
              }
            }
          }
          bool check = true;
          for (int r = 0; r <= 2; r++) {
            for (int c = 0; c < C; c++) {
              int cnt = state[r][c];
              for (int t = 0; t <= 3; t++) {
                int nxtr = r + dx[t];
                int nxtc = c + dy[t];
                if (nxtr >= 0 && nxtr <= 2 && nxtc >= 0 && nxtc < C) {
                  cnt += state[nxtr][nxtc];
                }
              }
              if (cnt > 1) {
                check = false;
                break;
              }
            }
          }
          if (check == true) {
            nextState[i][j].push_back(k);
          }
        }
      }
    }
    dp[0][0][0][0] = 1;
    for (int i = 0; i < R; i++) {
      int curState = i & 1;
      int nxtState = !curState;
      memset(dp[nxtState], 0, sizeof(dp[nxtState]));
      for (int numBase = 0; numBase <= R * C; numBase++) {
        for (int m1 = 0; m1 < (int) listState.size(); m1++) {
          for (int m2 = 0; m2 < (int) listState.size(); m2++) {
            if (dp[curState][numBase][m1][m2] == 0) {
              continue;
            }
            int curVal = dp[curState][numBase][m1][m2];
            for (int t = 0; t < (int) nextState[m1][m2].size(); t++) {
              int m3 = nextState[m1][m2][t];
              int countBase = __builtin_popcount(listState[m3]);
              update(dp[nxtState][numBase + countBase][m2][m3], curVal);
            }
          }
        }
      }
    }
    int ans = 0;
    for (int numBase = B; numBase <= R * C; numBase++) {
      for (int m1 = 0; m1 < (int) listState.size(); m1++) {
        for (int m2 = 0; m2 < (int) listState.size(); m2++) {
          update(ans, dp[R & 1][numBase][m1][m2]);
        }
      }
    }
    return ans;
  }
};

BasePlacement B;

int main () {
  cout << B.count(8, 10, 2);
  return 0;
}