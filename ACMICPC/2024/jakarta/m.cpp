#include <iostream> 
#include <string>
#include <vector> 
#include <cstring> 
#include <utility>
int n, m;
int numbMirrors = 0; 
std::vector <std::string> a;
std::vector <std::pair <char, int> > ans;  
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0}; 
bool visited[205][205][4];
bool ok[205][205];  
void dfs(int x, int y, int direction) {
  visited[x][y][direction] = true;
  if (a[x][y] == '.') {
    int nx = x + dx[direction];
    int ny = y + dy[direction];
    if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny][direction] == false) {
      dfs(nx, ny, direction); 
    } 
  }
  else if (a[x][y] == '/') {
    ok[x][y] = true; 
    if (direction == 2) {
      int nx = x + dx[1];
      int ny = y + dy[1];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny][1] == false) {
        dfs(nx, ny, 1); 
      }  
    }
    else if (direction == 3) {
      int nx = x + dx[0];
      int ny = y + dy[0];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny][0] == false) {
        dfs(nx, ny, 0); 
      }  
    }
    else if (direction == 0) {
      int nx = x + dx[3];
      int ny = y + dy[3];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny][3] == false) {
        dfs(nx, ny, 3); 
      }  
    }
    else if (direction == 1) {
      int nx = x + dx[2];
      int ny = y + dy[2];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny][2] == false) {
        dfs(nx, ny, 2); 
      }  
    }
  }
  else {
    ok[x][y] = true; 
    if (direction == 2) {
      int nx = x + dx[0];
      int ny = y + dy[0];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny][0] == false) {
        dfs(nx, ny, 0); 
      }  
    }
    else if (direction == 3) {
      int nx = x + dx[1];
      int ny = y + dy[1];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny][1] == false) {
        dfs(nx, ny, 1); 
      }  
    }
    else if (direction == 0) {
      int nx = x + dx[2];
      int ny = y + dy[2];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny][2] == false) {
        dfs(nx, ny, 2); 
      }  
    }
    else if (direction == 1) {
      int nx = x + dx[3];
      int ny = y + dy[3];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny][3] == false) {
        dfs(nx, ny, 3); 
      }  
    }
  }
}
void solve(int startx, int starty, int direction, const char &dir, const int &value) {
  std::memset(visited, false, sizeof(visited));
  std::memset(ok, false, sizeof(ok));
  dfs(startx, starty, direction);
  int total = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ok[i][j] == true) {
        total++; 
      }
    }
  }                                                                      
  if (total == numbMirrors) {
    ans.push_back(std::make_pair(dir, value)); 
  }
}

int main () {
  std::cin >> n >> m;
  a.resize(n); 
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '/' || a[i][j] == '\\') {
        numbMirrors++; 
      }
    }
  }
  for (int j = 0; j < m; j++) {
    solve(0, j, 2, 'N', j);
    solve(n - 1, j, 3, 'S', j);  
  }
  for (int i = 0; i < n; i++) {
    solve(i, 0, 0, 'W', i); 
    solve(i, m - 1, 1, 'E', i); 
  }
  std::cout << (int) ans.size() << std::endl;
  for (int i = 0; i < (int) ans.size(); i++) {
    std::cout << ans[i].first << ans[i].second + 1 << ' '; 
  }
  return 0; 
}