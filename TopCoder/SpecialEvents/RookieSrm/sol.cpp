#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 55;
int dist[MAX_N][MAX_N];
queue <pair <int, int> > myqueue;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

class SoFarAway {
  public:
  int distance(vector <string> plan) {
    int n = (int) plan.size();
    int m = (int) plan[0].size();
    int startx, starty, endx, endy;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (plan[i][j] == 'S') {
          startx = i;
          starty = j;
        }
        else if (plan[i][j] == 'D') {
          endx = i;
          endy = j;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        dist[i][j] = -1;
      }
    }
    dist[startx][starty] = 0;
    myqueue.push(make_pair(startx, starty));
    while (!myqueue.empty()) {
      pair <int, int> element = myqueue.front();
      myqueue.pop();
      for (int i = 0; i < 4; i++) {
        int xx = element.first + dx[i];
        int yy = element.second + dy[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && dist[xx][yy] == -1 && plan[xx][yy] != 'X') {
          dist[xx][yy] = dist[x][y] + 1;
          myqueue.push(make_pair(xx, yy));
        }
      }
    }
    return dist[endx][endy];
  }
};

int main () {
  return 0;
}