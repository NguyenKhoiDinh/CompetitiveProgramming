#include <iostream>
#include <vector> 
#include <string> 
int numTest; 
int state[1005][1005]; 
int n, m;
std::vector <std::string> a;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};  
bool dfs(int x, int y) {                      
  state[x][y] = 1; 
  bool found = false; 
  if (a[x][y] == '?') {
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
        if (state[nx][ny] == 1) {
          found = true;  
        }
        if (state[nx][ny] == 0) {
          if (dfs(nx, ny) == true) {
            found = true; 
          } 
        }
      }
    }
  }
  else {
    int i = a[x][y] - '0'; 
    int nx = x + dx[i];
    int ny = y + dy[i]; 
    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
      if (state[nx][ny] == 1) {
        found = true;  
      }
      if (state[nx][ny] == 0) {
        if (dfs(nx, ny) == true) {
          found = true;
        }
      }
    }
  }
  if (found == false) {
    state[x][y] = 2; 
  }
  return found;
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m;
    a.clear();
    a.resize(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i]; 
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 'R') {
          a[i][j] = '0';   
        }
        else if (a[i][j] == 'L') {
          a[i][j] = '1';
        }
        else if (a[i][j] == 'D') {
          a[i][j] = '2'; 
        }
        else if (a[i][j] == 'U') {
          a[i][j] = '3'; 
        }
        state[i][j] = 0; 
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (state[i][j] == 0) {
          dfs(i, j); 
        }
      }
    }
    int ans = 0; 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (state[i][j] == 1) {
          ans++; 
        }
      }
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}