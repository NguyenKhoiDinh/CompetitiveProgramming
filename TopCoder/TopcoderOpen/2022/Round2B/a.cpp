#include <bits/stdc++.h> 

using namespace std; 
int dx[4] = {0, 0, 1, -1}; 
int dy[4] = {1, -1, 0, 0}; 

class AddFlowers {
  public: 
  vector <string> add(vector <string> a) {
    int n = (int) a.size(); 
    int m = (int) a[0].size(); 
    vector <string> ans = a; 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 'F') {
          for (int k = 0; k < 4; k++) {
            int x = i + dx[k]; 
            int y = j + dy[k];
            if (x >= 0 && x < n && y >= 0 && y < m && ans[x][y] == '.') {
              ans[x][y] = 'F';   
            } 
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (ans[i][j] == 'F') {
          int numbAdj = 0; 
          for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < n && y >= 0 && y < m && ans[x][y] == 'F') {
              numbAdj++; 
            }
          }
          if (numbAdj < 2) {
            ans[i][j] = '.'; 
          }
        }
      }
    }
    return ans; 
  }
};

int main () {
  return 0; 
}