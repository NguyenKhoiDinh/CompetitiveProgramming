#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <fstream>

using namespace std;
const int MAX_N = 505;
string grid[MAX_N];
int dist[MAX_N][MAX_N];
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue <pair <int, int> > myQueue;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dist[i][j] = -1;
    }
  }
  dist[0][0] = 0;
  myQueue.push(make_pair(0, 0));
  while (!myQueue.empty()) {
    pair <int, int> element = myQueue.front();
    myQueue.pop();
    int x = element.first;
    int y = element.second;
    int v = grid[x][y] - '0';
    for (int i = 0; i < 4; i++) {
      int nextx = x + v * dx[i];
      int nexty = y + v * dy[i];
      if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < m && dist[nextx][nexty] == -1) {
        dist[nextx][nexty] = dist[x][y] + 1;
        myQueue.push(make_pair(nextx, nexty));
      }
    }
  }
  if (dist[n - 1][m - 1] == -1) {
    cout << "IMPOSSIBLE";
  }
  else {
    cout << dist[n - 1][m - 1];
  }
  return 0;
}