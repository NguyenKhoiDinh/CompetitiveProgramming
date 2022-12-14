#include <bits/stdc++.h> 

using namespace std; 
bool row[55], col[55]; 

class GalleryIllumination {
  public: 
  int countDarkCells(int R, int C, vector <string> a) {
    int n = R; 
    int m = C; 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 'O') {
          for (int x = i - 1; x >= 0; x--) {
            if (a[x][j] != '#' && a[x][j] != 'O') {
              a[x][j] = '*'; 
            }
            else {
              break; 
            }
          } 
          for (int x = i + 1; x < n; x++) {
            if (a[x][j] != '#' && a[x][j] != 'O') {
              a[x][j] = '*';
            }
            else {
              break; 
            }
          }
          for (int x = j - 1; x >= 0; x--) {
            if (a[i][x] != '#' && a[i][x] != 'O') {
              a[i][x] = '*'; 
            }
            else {
              break; 
            }
          } 
          for (int x = j + 1; x < m; x++) {
            if (a[i][x] != '#' && a[i][x] != 'O') {
              a[i][x] = '*';
            }
            else {
              break; 
            }
          }
        }
      }
    }
    int ans = 0; 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == '.') {
          if (row[i] == false && col[j] == false) {
            ans++;
          }
        }
      }
    }
    return ans;
  }
};

GalleryIllumination G;

int main () {
  return 0; 
}