#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 105; 
int dist[MAX_N][MAX_N];
char a[MAX_N][MAX_N];
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue <pair <int, int> > myqueue;

int main () {
  //freopen("input.txt", "r", stdin);
  cin >> n >> m;
  int startx = -1, starty = -1; 
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'B') {
        startx = i; 
        starty = j;
      }
      dist[i][j] = -1; 
    }
  }
  myqueue.push(make_pair(startx, starty)); 
  dist[startx][starty] = 0; 
  while (!myqueue.empty()) {
    pair <int, int> pr = myqueue.front();
    myqueue.pop();
    if (a[pr.first][pr.second] == 'C') {
      cout << dist[pr.first][pr.second];
      return 0; 
    }
    for (int i = 0; i < 4; i++) {
      int nxtx = pr.first + dx[i];
      int nxty = pr.second + dy[i];
      if (nxtx >= 1 && nxtx <= n && nxty >= 1 && nxty <= m && dist[nxtx][nxty] == -1 && a[nxtx][nxty] != '*') {
        dist[nxtx][nxty] = dist[pr.first][pr.second] + 1; 
        myqueue.push(make_pair(nxtx, nxty));
      }
    }
  }
  return 0; 
}