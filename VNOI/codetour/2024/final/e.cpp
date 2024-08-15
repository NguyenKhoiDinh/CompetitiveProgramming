#include <iostream> 
#include <vector> 
#include <utility> 
int n; 
std::vector <std::vector <int> > a; 
int numTest; 
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1}; 
std::vector <std::pair <int, int> > position[4000005];  
bool ok1[2005][2005], ok2[2005][2005]; 
bool visited[2005][2005]; 
bool dfs(int x, int y) {
  if (ok2[x][y] == true) {
    return true; 
  }
  visited[x][y] = true; 
  for (int i = 0; i < 8; i++) {
    int nxtx = x + dx[i];
    int nxty = y + dy[i];
    if (nxtx >= 0 && nxtx < n && nxty >= 0 && nxty < n && visited[nxtx][nxty] == false && a[nxtx][nxty] == a[x][y] && dfs(nxtx, nxty) == true) {
      return true;   
    }
  }
  return false; 
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    a.clear(); 
    a.resize(n);
    for (int i = 0; i < n; i++) {
      a[i].resize(n); 
    }
    for (int i = 0; i < n * n; i++) {
      position[i].clear(); 
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ok1[i][j] = false; 
        ok2[i][j] = false;
        visited[i][j] = false;  
        std::cin >> a[i][j]; 
        a[i][j]--;
        position[a[i][j]].push_back(std::make_pair(i, j)); 
      }
    }
    bool found = false; 
    for (int mex = 0; mex < n * n; mex++) {
      for (int i = 0; i < (int) position[mex].size(); i++) {
        std::pair <int, int> pos = position[mex][i];
        visited[pos.first][pos.second] = false; 
        if (pos.second == 0 || pos.first == n - 1) {
          ok1[pos.first][pos.second] = true; 
        } 
        if (pos.first == 0 || pos.second == n - 1) {
          ok2[pos.first][pos.second] = true; 
        }
      }
      bool flag = false; 
      for (int i = 0; i < (int) position[mex].size(); i++) {
        std::pair <int, int> pos = position[mex][i]; 
        if (ok1[pos.first][pos.second] == true && visited[pos.first][pos.second] == false) {
          if (dfs(pos.first, pos.second) == true) {
            flag = true;
            break;   
          }
        }
      }
      for (int i = 0; i < (int) position[mex].size(); i++) {
        std::pair <int, int> pos = position[mex][i];
        ok1[pos.first][pos.second] = false; 
        ok2[pos.first][pos.second] = false;
        visited[pos.first][pos.second] = false;   
      }
      if (flag == false) {
        found = true; 
        std::cout << mex + 1 << std::endl; 
        break; 
      }  
    }
    if (found == false) {
      std::cout << n * n + 1 << std::endl; 
    }
  }
  return 0; 
}