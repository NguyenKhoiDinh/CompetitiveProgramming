#include <iostream>
#include <math.h>
int numTest; 
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1}; 
int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};
bool visited[205][205][405];  
void dfs(int x, int y, int step) {
  visited[x][y][step] = true; 
  for (int i = 0; i < 8; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i]; 
    if (nx >= 0 && nx <= 200 && ny >= 0 && ny <= 200 && step + 1 <= 400 && visited[nx][ny][step + 1] == false) {
      dfs(nx, ny, step + 1); 
    }
  }
}

int main () {
  dfs(100, 100, 0); 
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int x, y;
    std::cin >> x >> y; 
    bool ok = false; 
    for (int y0 = y; y0 >= -100; y0--) {
      if (visited[x + 100][y0 + 100][y - y0 + 1] == true) {
        std::cout << "YES" << std::endl; 
        ok = true;
        break;
      }
    }
    if (ok == false) {
      std::cout << "NO" << std::endl;
    }  
  }
  return 0; 
}