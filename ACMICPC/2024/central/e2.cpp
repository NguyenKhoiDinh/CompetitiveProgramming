#include <bits/stdc++.h> 

using namespace std;
vector <string> a; 
int r, c, n;
vector <pair <int, int> > listCoord;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};        
int cost[20][20]; 
int f[(1 << 15) + 5][15];
int bfs(int pi, int pj) {
  pair <int, int> start, end;
  start = listCoord[pi];
  end = listCoord[pj];
  vector <vector <int> > dist(r); 
  for (int i = 0; i < r; i++) {
    dist[i].resize(c, -1); 
  }
  queue <pair <int, int> > myqueue;
  myqueue.push(make_pair(start.first, start.second));
  dist[start.first][start.second] = 0; 
  while (myqueue.empty() == false) {
    pair <int, int> pr = myqueue.front();
    myqueue.pop(); 
    int x = pr.first;
    int y = pr.second;               
    for (int i = 0; i < 4; i++) {
      int nxtx = x + dx[i];
      int nxty = y + dy[i];
      if (nxtx >= 0 && nxtx < r && nxty >= 0 && nxty < c && a[nxtx][nxty] != '#' && dist[nxtx][nxty] == -1) {
        myqueue.push(make_pair(nxtx, nxty));
        dist[nxtx][nxty] = dist[x][y] + 1;  
      } 
    }
  }
  return dist[end.first][end.second];   
}

int main () {
  cin >> r >> c >> n;
  a.resize(r);
  for (int i = 0; i < r; i++) {
    cin >> a[i]; 
    for (int j = 0; j < c; j++) {
      if (a[i][j] == 'S') {              
        listCoord.push_back(make_pair(i, j)); 
      }
    }
  }
  n = (int) listCoord.size(); 
  listCoord.push_back(make_pair(0, 0)); 
  for (int i = 0; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      cost[i][j] = cost[j][i] = bfs(i, j);
      if (cost[i][j] == -1) {
        cout << "-1"; 
        return 0; 
      }  
    }
  }
  const int inf = 1000000007; 
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int u = 0; u < n; u++) {
      f[mask][u] = inf; 
    }
  }
  for (int u = 0; u < n; u++) {
    f[1 << u][u] = cost[u][n]; 
  }
  for (int mask = 1; mask < (1 << n); mask++) {
    for (int u = 0; u < n; u++) {
      if (f[mask][u] != inf) {
        for (int v = 0; v < n; v++) {
          if ((mask & (1 << v)) == 0) {
            f[mask | (1 << v)][v] = min(f[mask | (1 << v)][v], f[mask][u] + cost[u][v]);
          }
        }
      }
    }
  }
  int ans = inf; 
  for (int u = 0; u < n; u++) {
    ans = min(ans, f[(1 << n) - 1][u]); 
  }
  cout << ans; 
  return 0; 
}