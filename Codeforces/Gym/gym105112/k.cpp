#include <iostream>
#include <vector>    
int n;
int a, b;
int c, d;  
bool visited[505][505][2]; 
void dfs(int x, int y, int change) {
  visited[x][y][change] = true;
  std::vector <int> dx, dy;
  if (change == 0) {
    dx = {a, a, -a, -a, b, b, -b, -b};
    dy = {b, -b, b, -b, a, -a, a, -a};   
  } 
  else {
    dx = {c, c, -c, -c, d, d, -d, -d}; 
    dy = {d, -d, d, -d, c, -c, c, -c}; 
  }
  for (int i = 0; i < 8; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i]; 
    if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && visited[nx][ny][!change] == false) {
      dfs(nx, ny, !change); 
    }
  }
}
int main () {
  std::cin >> n;
  std::cin >> a >> b;
  std::cin >> c >> d;
  dfs(1, 1, 0);
  dfs(1, 1, 1); 
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (visited[i][j][0] == true || visited[i][j][1] == true) {
        ans++; 
      }
    }
  }
  std::cout << ans; 
  return 0; 
}