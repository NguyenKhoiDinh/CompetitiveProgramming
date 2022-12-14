#include <iostream>
#include <string> 
#include <utility>
#include <vector>
#include <math.h>
int numTest; 
std::string a[55];
int n, m;  
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1}; 
std::vector <std::pair <int, int> > component; 

void dfs(int x, int y) {
  a[x][y] = '.'; 
  component.push_back(std::make_pair(x, y)); 
  for (int i = 0; i < 8; i++) {
    int nextx = x + dx[i];
    int nexty = y + dy[i];
    if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < m && a[nextx][nexty] == '*') {
      dfs(nextx, nexty); 
    }
  }
}

int distance(const std::pair <int, int> &a, const std::pair <int, int> &b) {
  return std::abs(a.first - b.first) + std::abs(a.second - b.second); 
}

bool check(const std::vector <std::pair <int, int> > a) {
  if (a[0].first == a[1].first && a[1].first == a[2].first) {
    return false; 
  }
  if (a[0].second == a[1].second && a[1].second == a[2].second) {
    return false; 
  }
  if (distance(a[0], a[1]) == 4 || distance(a[1], a[2]) == 4 || distance(a[0], a[2]) == 4) {
    return false; 
  }
  if (distance(a[0], a[1]) + distance(a[0], a[2]) == 2 || distance(a[1], a[0]) + distance(a[1], a[2]) == 2 || distance(a[2], a[0]) + distance(a[2], a[1]) == 2) {
    return true; 
  }
  return false;  
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
      std::cin >> a[i]; 
    }
    bool found = true; 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == '*') {
          component.clear(); 
          dfs(i, j);
          if ((int) component.size() != 3) {
            found = false;   
          }
          if (check(component) == false) {
            found = false; 
          } 
        }
      }
    }
    std::cout << (found == true ? "YES" : "NO") << std::endl; 
  }
  return 0; 
}