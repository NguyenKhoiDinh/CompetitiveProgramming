#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <utility>
int numTest; 
int n, m;
std::vector <std::string> a; 
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};                  
std::vector <std::vector <bool> > used;
int numb = 0; 
std::vector <std::pair <int, int> > save; 

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
  used[x][y] = true; 
  save.push_back(std::make_pair(x, y)); 
  for (int i = 0; i < 4; i++) {
    int nxtx = x + dx[i];
    int nxty = y + dy[i];
    if (nxtx >= 0 && nxtx < n && nxty >= 0 && nxty < m && a[nxtx][nxty] == 'W' && used[nxtx][nxty] == false && dfs(nxtx, nxty) == false) {
      return false;       
    }
  }
  return true; 
}

void dfsCount(int x, int y) {                          
  used[x][y] = true; 
  numb++; 
  for (int i = 0; i < 4; i++) {
    int nxtx = x + dx[i];
    int nxty = y + dy[i];
    if (nxtx >= 0 && nxtx < n && nxty >= 0 && nxty < m && a[nxtx][nxty] == 'W' && used[nxtx][nxty] == false) {
      dfsCount(nxtx, nxty);          
    }
  }
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
    used.clear();
    used.resize(n);
    for (int i = 0; i < n; i++) {
      used[i].resize(m, false); 
    }
    int ans = 0;                               
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 'W' && used[i][j] == false) {
          for (int t = 0; t < 4; t++) {
            int ii = i + dx[t];
            int jj = j + dy[t];           
            if (ii >= 0 && ii < n && jj >= 0 && jj < m && used[ii][jj] == false && a[ii][jj] == '.') {
              a[ii][jj] = 'B';
              used[ii][jj] = true;
              numb = 0; 
              for (int tt = 0; tt < 4; tt++) {
                int iii = ii + dx[tt];
                int jjj = jj + dy[tt]; 
                if (iii >= 0 && iii < n && jjj >= 0 && jjj < m && used[iii][jjj] == false && a[iii][jjj] == 'W') {
                  bool check = dfs(iii, jjj);
                  while (save.empty() == false) {
                    used[save.back().first][save.back().second] = false; 
                    save.pop_back(); 
                  }
                  if (check == true) {
                    dfsCount(iii, jjj);   
                  }  
                }
              }
              a[ii][jj] = '.';
              ans = std::max(ans, numb); 
            }
          }
        }
      }
    }
    std::cout << ans << std::endl;
    std::cerr << "Test Case #" << testCase << "     DONE!!!" << std::endl;  
  }
  return 0; 
}