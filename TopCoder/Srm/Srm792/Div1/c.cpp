#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 11;
int dp[2][MAX_N][(1 << 20) + 3];
//0: white
//1: green with 1 white
//2: green with both white
//3: rest
int pow4[MAX_N];
char board[MAX_N][MAX_N];
vector <int> listState[(1 << 20) + 3];

vector <int> convertToArray(int mask, int width) {
  vector <int> res;
  while ((int) res.size() < width) {
    int lastState = mask % 4;
    mask /= 4;
    res.push_back(lastState);
  }
  return res;
}

void init(int width) {
  pow4[0] = 1;
  for (int i = 1; i <= 10; i++) {
    pow4[i] = pow4[i - 1] * 4;
  }
  for (int mask = 0; mask < pow4[width]; mask++) {
    listState[mask] = convertToArray(mask, width);
  }
}

void updateMax(int &a, int b) {
  if (a < b) {
    a = b;
  }
}

class EllysFlags {
  public:
  int getMax(vector <string> paper) {
    int n = (int) paper.size();
    int m = (int) paper[0].size();
    int width = m;
    init(width);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        board[i][j] = paper[i - 1][j - 1];
      }
    }
    for (int i = 0; i <= 1; i++) {
      for (int j = 0; j <= m; j++) {
        for (int mask = 0; mask < pow4[width]; mask++) {
          dp[i][j][mask] = -1;
        }
      }
    }
    int res = -1;
    dp[0][m][0] = 0;
    for (int row = 0; row <= n; row++) {
      int curRow = row % 2;
      int nxtRow = curRow;
      for (int col = 0; col <= m; col++) {
        int newrow = row;
        int newcol = col;
        newcol++;
        if (newcol == m + 1) {
          newrow++;
          newcol = 1;
          nxtRow = !nxtRow;
          for (int j = 0; j <= m; j++) {
            for (int mask = 0; mask < pow4[width]; mask++) {
              dp[nxtRow][j][mask] = -1;
            }
          }
        }
        for (int mask = 0; mask < pow4[width]; mask++) {
          if (dp[curRow][col][mask] == -1) {
            continue;
          }
          int curVal = dp[curRow][col][mask];
          if (row == n && col == m) {
            res = max(res, curVal);
            continue;
          }
          vector <int> &state = listState[mask];
          if (board[newrow][newcol] == 'W') {
            int newmask = mask / 4;
            updateMax(dp[nxtRow][newcol][newmask], curVal);
          }
          if (board[newrow][newcol] == 'R' || board[newrow][newcol] == 'W') {
            int val = 0;
            if (newcol > 1) {
              if (state.back() == 1) {
                val++;
              }
              else if (state.back() == 2) {
                val += 2;
              }
            }
            if (newrow > 1) {
              if (state[0] == 1) {
                val++;
              }
              else if (state[0] == 2) {
                val += 2;
              }
            }
            int newmask = mask / 4;
            newmask += 3 * pow4[width - 1];
            updateMax(dp[nxtRow][newcol][newmask], curVal + val);
          }
          if (board[newrow][newcol] == 'G' || board[newrow][newcol] == 'W') {
            int lastState = 3;
            if (newcol > 1) {
              if (state.back() == 0) {
                lastState = 1;
              }
            }
            if (newrow > 1) {
              if (state[0] == 0) {
                if (lastState == 1) {
                  lastState = 2;
                }
                else {
                  lastState = 1;
                }
              }
            }
            int newmask = mask / 4;
            newmask += lastState * pow4[width - 1];
            updateMax(dp[nxtRow][newcol][newmask], curVal);
          }
        }
      }
    }
    return res;
  }
};

EllysFlags E;

int main () {
  cout << E.getMax({"WGWWR",
 "GRGRG",
 "RWGRW",
 "GGWGR"});
  return 0;
}