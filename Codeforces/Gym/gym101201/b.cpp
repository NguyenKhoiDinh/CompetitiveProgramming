#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <queue>
#include <functional>

using namespace std;
const int MAX_N = 53;
const int inf = 100007;
int dist[MAX_N][MAX_N][MAX_N];
string commands;
string a[MAX_N];
int n, m, startx, starty, endx, endy, len;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct element {
  int x, y, l;
  int distance;
  bool operator < (const element &hs) const {
    return distance > hs.distance;
  }
};

int findStep(char command) {
  if (command == 'L') {
    return 3;
  }
  else if (command == 'R') {
    return 2;
  }
  else if (command == 'U') {
    return 1;
  }
  else {
    return 0;
  }
}

void Dijkstra() {
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      for (int l = 0; l <= len; l++) {
        dist[x][y][l] = inf;
      }
    }
  }
  dist[startx][starty][0] = 0;
  priority_queue <element> pq;
  pq.push((element) {startx, starty, 0, 0});
  while (!pq.empty()) {
    element e = pq.top();
    int x = e.x;
    int y = e.y;
    int l = e.l;
    int distance = e.distance;
    pq.pop();
    if (distance != dist[x][y][l]) {
      continue;
    }
    if (x == endx && y == endy) {
      cout << distance;
      return;
    }
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] != '#') {
        if (dist[xx][yy][l] > dist[x][y][l] + 1) {
          dist[xx][yy][l] = dist[x][y][l] + 1;
          pq.push((element) {xx, yy, l, dist[xx][yy][l]});
        }
      }
    }
    if (l < len) {
      if (dist[x][y][l + 1] > dist[x][y][l] + 1) {
        dist[x][y][l + 1] = dist[x][y][l] + 1;
        pq.push((element) {x, y, l + 1, dist[x][y][l + 1]});
      }
      int nxtStep = findStep(commands[l]);
      int xx = x + dx[nxtStep];
      int yy = y + dy[nxtStep];
      if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] != '#') {
        if (dist[xx][yy][l + 1] > dist[x][y][l]) {
          dist[xx][yy][l + 1] = dist[x][y][l];
          pq.push((element) {xx, yy, l + 1, dist[xx][yy][l + 1]});
        }
      }
      else {
        if (dist[x][y][l + 1] > dist[x][y][l]) {
          dist[x][y][l + 1] = dist[x][y][l];
          pq.push((element) {x, y, l + 1, dist[x][y][l + 1]});
        }
      }
    }
  }
}

int main () {
  freopen("input.txt", "r", stdin);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> commands;
  len = (int) commands.size();
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      if (a[x][y] == 'R') {
        startx = x;
        starty = y;
      }
      else if (a[x][y] == 'E') {
        endx = x;
        endy = y;
      }
    }
  }
  Dijkstra();
  return 0;
}