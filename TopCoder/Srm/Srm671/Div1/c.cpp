#include <bits/stdc++.h>

using namespace std;
const int MAX_H = 15;
const int MAX_W = 32;
int dp[MAX_H * MAX_W][(1 << 14) + 5];
int ways[MAX_H * MAX_W][(1 << 14) + 5];
int steps[MAX_H][MAX_W];
vector <pair <int, int> > cell;

void update(int &a, int b, int MOD) {
  (a += b) %= MOD;
}

class BearDestroys {
  public:
  int sumUp(int W, int H, int MOD) {
    int startx = 1;
    int starty = 1;
    while (true) {
      int x = startx;
      int y = starty;
      while (true) {
        cell.push_back(make_pair(x, y));
        steps[x][y] = (int) cell.size();
        x++;
        y--;
        if (x > H || y < 1) {
          break;
        }
      }
      if (startx == H && starty == W) {
        break;
      }
      if (starty < W) {
        starty++;
      }
      else {
        startx++;
      }
    }
    ways[1][0] = 1;
    for (int i = 1; i <= W * H; i++) {
      for (int mask = 0; mask < (1 << (H + 1)); mask++) {
        if (dp[i][mask] == 0 && ways[i][mask] == 0) {
          continue;
        }
        int x = cell[i - 1].first;
        int y = cell[i - 1].second;
        if ((mask & 1) == 0) {
          //South
          int nxtMask = mask >> 1;
          int fallDown = 0;
          if (x < H && ((nxtMask & (1 << (steps[x + 1][y] - i - 1))) == 0)) {
            fallDown = 1;
            nxtMask |= (1 << (steps[x + 1][y] - i - 1));
          }
          else if (y < W && ((nxtMask & (1 << (steps[x][y + 1] - i - 1))) == 0)) {
            fallDown = 1;
            nxtMask |= (1 << (steps[x][y + 1] - i - 1));
          }
          update(dp[i + 1][nxtMask], (dp[i][mask] + fallDown * ways[i][mask]) % MOD, MOD);
          update(ways[i + 1][nxtMask], ways[i][mask], MOD);
          //East
          nxtMask = mask >> 1;
          fallDown = 0;
          if (y < W && ((nxtMask & (1 << (steps[x][y + 1] - i - 1))) == 0)) {
            fallDown = 1;
            nxtMask |= (1 << (steps[x][y + 1] - i - 1));
          }
          else if (x < H && ((nxtMask & (1 << (steps[x + 1][y] - i - 1))) == 0)) {
            fallDown = 1;
            nxtMask |= (1 << (steps[x + 1][y] - i - 1));
          }
          update(dp[i + 1][nxtMask], (dp[i][mask] + fallDown * ways[i][mask]) % MOD, MOD);
          update(ways[i + 1][nxtMask], ways[i][mask], MOD);
        }
        else {
          int nxtMask = mask >> 1;
          update(dp[i + 1][nxtMask], (2 * dp[i][mask]) % MOD, MOD);
          update(ways[i + 1][nxtMask], (2 * ways[i][mask]) % MOD, MOD);
        }
      }
    }
    return dp[W * H + 1][0];
  }
};
BearDestroys B;

int main () {
  cout << B.sumUp(4, 3, 999999937);
  return 0;
}