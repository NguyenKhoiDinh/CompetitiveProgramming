#include <bits/stdc++.h> 

using namespace std; 
int dp[(1 << 15) + 5][15][6]; 
struct element {
  int x, y, z; 
};
element boxes[15][6]; 
vector <pair <int, int> > saveNextBox[15][6]; 

class BoxTower {
  public: 
  int tallestTower(vector <int> x, vector <int> y, vector <int> z) {
    int n = (int) x.size(); 
    for (int i = 0; i < n; i++) {
      boxes[i][0] = (element) {x[i], y[i], z[i]};
      boxes[i][1] = (element) {x[i], z[i], y[i]};
      boxes[i][2] = (element) {y[i], x[i], z[i]};
      boxes[i][3] = (element) {y[i], z[i], x[i]};
      boxes[i][4] = (element) {z[i], x[i], y[i]};
      boxes[i][5] = (element) {z[i], y[i], x[i]};
    }
    for (int i = 0; i < n; i++) {
      for (int per = 0; per < 6; per++) {
        for (int j = 0; j < n; j++) {
          if (j != i) {
            for (int nextPer = 0; nextPer < 6; nextPer++) {
              if (boxes[j][nextPer].x <= boxes[i][per].x && boxes[j][nextPer].y <= boxes[i][per].y) {
                saveNextBox[i][per].push_back(make_pair(j, nextPer)); 
              }
            }
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int per = 0; per < 6; per++) {
        dp[1 << i][i][per] = boxes[i][per].z; 
      }
    }
    for (int mask = 1; mask < (1 << n); mask++) {
      for (int i = 0; i < n; i++) {
        for (int per = 0; per < 6; per++) {
          if (dp[mask][i][per] == 0) {
            continue; 
          }
          for (int j = 0; j < (int) saveNextBox[i][per].size(); j++) {
            pair <int, int> neighbor = saveNextBox[i][per][j]; 
            int nextBox = neighbor.first; 
            if ((mask & (1 << nextBox)) > 0) {
              continue; 
            }
            int direction = neighbor.second; 
            dp[mask | (1 << nextBox)][nextBox][direction] = max(dp[mask | (1 << nextBox)][nextBox][direction], dp[mask][i][per] + boxes[nextBox][direction].z); 
          }
        }
      }
    }
    int ans = 0; 
    for (int mask = 1; mask < (1 << n); mask++) {
      for (int i = 0; i < n; i++) {
        for (int per = 0; per < 6; per++) {
          ans = max(ans, dp[mask][i][per]); 
        }
      }
    }
    return ans; 
  }
};
BoxTower B; 

int main () {
  cout << B.tallestTower({20, 30} ,
{20, 33}                           ,
{20, 10}      );
  return 0; 
}