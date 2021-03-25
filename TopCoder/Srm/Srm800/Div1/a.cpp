#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 25;
bool visited[MAX_N][MAX_N][MAX_N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, int val, int n, int m, vector <string> &a) {
  visited[x][y][val] = true;
  for (int i = 0; i < 4; i++) {
    int nxtx = x + dx[i];
    int nxty = y + dy[i];
    if (nxtx < 0 || nxtx >= n || nxty < 0 || nxty >= m) {
      continue;
    }
    if (a[nxtx][nxty] == '#') {
      continue;
    }
    int newVal = val;
    if ('0' <= a[nxtx][nxty] && a[nxtx][nxty] <= '9') {
      newVal += a[nxtx][nxty] - '0';
    }
    else if (a[nxtx][nxty] == 'S') {
      newVal = 0;
    }
    if (visited[nxtx][nxty][newVal] == false) {
      dfs(nxtx, nxty, newVal, n, m, a);
    }
  }
}

class PoisonedSwamp {
  public:
  string cross(vector <string> a) {
    int n = (int) a.size();
    int m = (int) a[0].size();
    dfs(0, 0, 0, n, m, a);
    bool ans = false;
    for (int x = 0; x <= 9; x++) {
      if (visited[n - 1][m - 1][x] == true) {
        ans = true;
        break;
      }
    }
    return (ans == true ? "possible" : "impossible");
  }
};

PoisonedSwamp P;

int main () {
  cout << P.cross({".111111111.",
 ".#########.",
 "..22222...."});
  return 0;
}