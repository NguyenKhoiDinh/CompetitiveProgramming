#include <iostream> 
#include <math.h> 
#include <vector> 
#include <string> 
// 0: right, 1: down, 2: left, 3: up
struct vertex {
  int x, y, dir; 
};
vertex nxt[1005][1005][4]; 
bool in[1005][1005][4]; 
int dist[1005][1005][4]; 
int n, m, numTest;
std::vector <std::string> a; 
void dfs(int x, int y, int dir) {
  std::cout << x << "    " << y << "    " << dir << std::endl;
  vertex v = nxt[x][y][dir];
  if (v.x == -1) {
    return; 
  } 
  dist[v.x][v.y][v.dir] = dist[x][y][dir] + 1; 
  dfs(v.x, v.y, v.dir); 
}

int main () {
  std::cout << "0: right, 1: down, 2: left, 3: up" << std::endl;
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m;
    a.clear();
    a.resize(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int dir = 0; dir <= 3; dir++) {
          nxt[i][j][dir] = (vertex) {-1, -1, -1};
          in[i][j][dir] = false;
          dist[i][j][dir] = -1;   
        }
      }
    }
    for (int i = 0; i < n; i++) {
      std::cin >> a[i]; 
    }
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < m; y++) {
        if (a[x][y] == '1') {
          if (x > 0 && a[x - 1][y] == '1') {
            nxt[x - 1][y][0] = (vertex) {x, y, 3};
            in[x][y][3] = true;  
          }  
          if (x + 1 < n && a[x + 1][y] == '1') {
            nxt[x + 1][y][2] = (vertex) {x, y, 1};
            in[x][y][1] = true;  
          }
          if (y + 1 < m && a[x][y + 1] == '1') {
            nxt[x][y + 1][1] = (vertex) {x, y, 0}; 
            in[x][y][0] = true; 
          }
          if (y > 0 && a[x][y - 1] == '1') {
            nxt[x][y - 1][3] = (vertex) {x, y, 2}; 
            in[x][y][2] = true; 
          }
        }
      }
    }
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < m; y++) {
        for (int dir = 0; dir <= 3; dir++) {
          if (a[x][y] == '1' && in[x][y][dir] == false && dist[x][y][dir] == -1) {
            dist[x][y][dir] = 1; 
            dfs(x, y, dir); 
            std::cout << "#############" << std::endl;
          }
        }
      }
    }
    int ans = 0;
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < m; y++) {
        if (a[x][y] == '0') {
          continue; 
        }
        int total = 0;
        for (int dir = 0; dir <= 3; dir++) {
          total += dist[x][y][dir]; 
        }  
        ans = std::max(ans, total); 
      }
    }
    std::cout << ans - 3 << std::endl;
  }
  return 0; 
}