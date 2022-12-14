#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 105; 
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char a[MAX_N][MAX_N];
int n, m; 

void dfs(int x, int y) {
  a[x][y] = '.';
  for (int i = 0; i < 4; i++) {
    int nxtx = x + dx[i];
    int nxty = y + dy[i]; 
    if (nxtx >= 0 && nxtx < n && nxty >= 0 && nxty < m && a[nxtx][nxty] == '#') {
      dfs(nxtx, nxty);
    } 
  }
}

int main () {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  int res = 0; 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '#') {
        res++;
        dfs(i, j);
      }
    }
  }
  cout << res; 
  return 0; 
}