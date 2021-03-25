#include <iostream>
#include <functional>
#include <queue>
#include <vector>
#include <math.h>
#include <fstream>
#include <utility>
struct element {
  int distance;
  int x, y;
  bool operator < (const element &e) const {
    return distance > e.distance;
  }
};

using namespace std;
const int MAX_N = 1000005;
const int inf = 100000007;

int dx[8] = {1, -1, 1, -1, 1, -1, 0, 0};
int dy[8] = {1, -1, -1, 1, 0, 0, 1, -1};
string a[MAX_N];
int n, m;

void Dijkstra() {
  vector <vector <int> > dist;
  dist.resize(n);
  for (int i = 0; i < n; i++) {
    dist[i].resize(m, inf);
  }
  priority_queue <element> pq;
  for (int i = 0; i < n; i++) {
    if (a[i][0] == '.') {
      pq.push((element) {1, i, 0});
      dist[i][0] = 1;
    }
    else if (a[i][0] == '#') {
      pq.push((element) {0, i, 0});
      dist[i][0] = 0;
    }
  }
  for (int j = 0; j < m; j++) {
    if (a[n - 1][j] == '.') {
      pq.push((element) {1, n - 1, j});
      dist[n - 1][j] = 1;
    }
    else if (a[n - 1][j] == '#') {
      pq.push((element) {0, n - 1, j});
      dist[n - 1][j] = 0;
    }
  }
  while (!pq.empty()) {
    element e = pq.top();
    pq.pop();
    if (e.distance != dist[e.x][e.y]) {
      continue;
    }
    if (e.x == 0 || e.y == m - 1) {
      cout << e.distance;
      return;
    }
    for (int i = 0; i < 8; i++) {
      int x = e.x + dx[i];
      int y = e.y + dy[i];
      if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '@') {
        if (dist[x][y] > e.distance + (a[x][y] == '.' ? 1 : 0)) {
          dist[x][y] = e.distance + (a[x][y] == '.' ? 1 : 0);
          pq.push((element) {dist[x][y], x, y});
        }
      }
    }
  }
  cout << -1;
}

int main () {
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
  while (true) {
    cin >> n >> m;
    if (n == 0 && m == 0) {
      break;
    }
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    Dijkstra();
    cout << endl;
  }
  return 0;
}