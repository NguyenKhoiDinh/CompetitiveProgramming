#include <iostream>
#include <queue>
#include <fstream>

using namespace std;
const int MAX_N = 305;
struct element {
  int value, x, y;
  bool operator < (const element &other) const {
    return value < other.value;
  }
};
bool visited[MAX_N][MAX_N];
int R, C, numTest;
int a[MAX_N][MAX_N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        cin >> a[i][j];
        visited[i][j] = false;
      }
    }
    priority_queue <element> pq;
    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        pq.push((element) {a[i][j], i, j});
      }
    }
    long long res = 0;
    while (!pq.empty()) {
      element e = pq.top();
      pq.pop();
      int x = e.x;
      int y = e.y;
      int value = e.value;
      if (visited[x][y] == true) {
        continue;
      }
      visited[x][y] = true;
      for (int i = 0; i < 4; i++) {
        int nxtx = e.x + dx[i];
        int nxty = e.y + dy[i];
        if (nxtx < 1 || nxtx > R || nxty < 1 || nxty > C) {
          continue;
        }
        if (value - 1 > a[nxtx][nxty]) {
          pq.push((element) {value - 1, nxtx, nxty});
          res += value - 1 - a[nxtx][nxty];
          a[nxtx][nxty] = value - 1;
        }
      }
    }
    cout << "Case #" << testCase << ": ";
    cout << res << endl;
  }
  return 0;
}