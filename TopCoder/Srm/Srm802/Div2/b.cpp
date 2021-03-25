#include <bits/stdc++.h>

using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool visited[55][55];
bool check[55][55];

void dfs(int x, int y, int n, int m) {
  visited[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int xx = x + dx[i];
    int yy = y + dy[i];
    if (xx >= 0 && xx < n && yy >= 0 && yy < m && visited[xx][yy] == false && check[xx][yy] == false) {
      dfs(xx, yy, n, m);
    }
  }
}

class TheQuestForGold {
  public:
  string explore(vector <string> a) {
    int n = (int) a.size();
    int m = (int) a[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 'P') {
          for (int x = 0; x < 4; x++) {
            int xx = i + dx[x];
            int yy = j + dy[x];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] != 'T') {
              check[xx][yy] = true;
            }
          }
        }
      }
    }
    int startx, starty, endx, endy;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 'S') {
          startx = i;
          starty = j;
        }
        else if (a[i][j] == 'T') {
          endx = i;
          endy = j;
        }
      }
    }
    if (check[startx][starty] == true) {
      return "no gold";
    }
    dfs(startx, starty, n, m);
    return (visited[endx][endy] == false ? "no gold" : "gold");
  }
};