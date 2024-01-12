#include <iostream>
#include <string>
#include <vector>
int numTest; 
int n, m;
std::vector <std::string> a; 
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
std::vector <std::vector <bool> > visited;  

bool valid(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int nxtx = x + dx[i];
    int nxty = y + dy[i];
    if (nxtx >= 0 && nxtx < n && nxty >= 0 && nxty < m && a[nxtx][nxty] == '.') {
      return false; 
    }
  }
  return true; 
}

bool dfs(int x, int y) {
  if (valid(x, y) == false) {
    return false; 
  }  
  visited[x][y] = true; 
  for (int i = 0; i < 4; i++) {
    int nxtx = x + dx[i];
    int nxty = y + dy[i];
    if (nxtx >= 0 && nxtx < n && nxty >= 0 && nxty < m && a[nxtx][nxty] == 'W' && visited[nxtx][nxty] == false && dfs(nxtx, nxty) == false) {
      return false;       
    }
  }
  return true; 
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> n >> m;
    a.clear();
    a.resize(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i]; 
    }
    visited.clear(); 
    visited.resize(n);
    for (int i = 0; i < n; i++) {
      visited[i].resize(m, false);
    }
    bool ans = false;
    for (int i = 0; i < n; i++) {
      if (ans == true) {
        break; 
      }
      for (int j = 0; j < m; j++) {
        if (a[i][j] == '.') {
          a[i][j] = 'B'; 
          for (int t = 0; t < 4; t++) {
            int x = i + dx[t];
            int y = j + dy[t]; 
            if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 'W') {
              for (int ii = 0; ii < n; ii++) {
                for (int jj = 0; jj < m; jj++) {
                  visited[ii][jj] = false; 
                }
              }
              if (dfs(x, y) == true) {
                ans = true; 
                break;
              }
            }
          }
          a[i][j] = '.';
        }
      }
    }
    std::cout << (ans == true ? "YES" : "NO") << std::endl; 
  }
  return 0; 
}