#include <iostream>
#include <string>
#include <vector>
#include <utility> 
#include <queue>
#include <algorithm>
int n, m; 
std::vector <std::string> a; 
std::vector <std::vector <std::vector <std::pair <int, int> > > > trace; 
std::vector <char> ans; 
void dfs(int x, int y) {
  if (x > 0 && a[x - 1][y] != '#') {
    trace[x - 1][y].push_back(std::make_pair(x, y));
    dfs(x - 1, y);  
  }
  if (y > 0 && a[x][y - 1] != '#') {
    trace[x][y - 1].push_back(std::make_pair(x, y));
    dfs(x, y - 1);  
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin >> n >> m;
  a.resize(n);
  trace.resize(n); 
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    trace[i].resize(m);  
  }
  dfs(n - 1, m - 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((int) trace[i][j].size() == 2 && a[trace[i][j][0].first][trace[i][j][0].second] > a[trace[i][j][1].first][trace[i][j][1].second]) {
        std::swap(trace[i][j][0], trace[i][j][1]); 
      }
    }
  }
    
  return 0; 
}