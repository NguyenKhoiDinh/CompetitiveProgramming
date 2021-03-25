#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 42;
int dist[MAX_N][MAX_N][MAX_N][MAX_N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector <string> a;
int n, m;

struct element {
  int xa, ya, xb, yb;
};

bool check(int xa, int ya, int xb, int yb, const vector <string> &a) {
  int n = (int) a.size();
  int m = (int) a[0].size();
  if (xa >= 0 && xa < n && ya >= 0 && ya < m && xb >= 0 && xb < n && yb >= 0 && yb < m) {
    if (xa != xb || ya != yb) {
      if (a[xa][ya] != '#' && a[xb][yb] != '#') {
        if (dist[xa][ya][xb][yb] == -1) {
          return true;
        }
      }
    }
  }
  return false;
}

int move(vector <string> a) {
  for (int xa = 0; xa < MAX_N; xa++) {
    for (int ya = 0; ya < MAX_N; ya++) {
      for (int xb = 0; xb < MAX_N; xb++) {
        for (int yb = 0; yb < MAX_N; yb++) {
          dist[xa][ya][xb][yb] = -1;
        }
      }
    }
  }
  int startxA, startyA, startxB, startyB, endxA, endyA, endxB, endyB;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'A') {
        startxA = i;
        startyA = j;
      }
      else if (a[i][j] == 'B') {
        startxB = i;
        startyB = j;
      }
      else if (a[i][j] == 'a') {
        endxA = i;
        endyA = j;
      }
      else if (a[i][j] == 'b') {
        endxB = i;
        endyB = j;
      }
    }
  }
  queue <element> myqueue;
  dist[startxA][startyA][startxB][startyB] = 0;
  myqueue.push((element) {startxA, startyA, startxB, startyB});
  while (!myqueue.empty()) {
    element cur = myqueue.front();
    myqueue.pop();
    int xa = cur.xa;
    int ya = cur.ya;
    int xb = cur.xb;
    int yb = cur.yb;
    if (xa == endxA && ya == endyA && xb == endxB && yb == endyB) {
      return dist[xa][ya][xb][yb];
    }
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        int nxtxA = xa + dx[i];
        int nxtyA = ya + dy[i];
        int nxtxB = xb + dx[j];
        int nxtyB = yb + dy[j];
        if ((nxtxA == xb && nxtyA == yb) && (nxtxB == xa && nxtyB == ya)) {
          continue;
        }
        if (check(nxtxA, nxtyA, nxtxB, nxtyB, a) == true) {
          dist[nxtxA][nxtyA][nxtxB][nxtyB] = dist[xa][ya][xb][yb] + 1;
          myqueue.push((element) {nxtxA, nxtyA, nxtxB, nxtyB});
        }
      }
    }
  }
  return -1;
}


int main () {
  cout << T.move({"bA......Ba",
".........."});
  return 0;
}