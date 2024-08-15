#include <iostream> 
#include <cstring> 
#include <utility> 
#include <algorithm>
std::pair <int, int> change[10][10];
int numTest;
int n, x, y;  
int dp[102][102][102]; 

int main () {
  change[0][1] = std::make_pair(4, 0);
  change[0][2] = std::make_pair(2, 1);
  change[0][3] = std::make_pair(2, 1);
  change[0][4] = std::make_pair(3, 1);
  change[0][5] = std::make_pair(2, 1);
  change[0][6] = std::make_pair(1, 1);  
  change[0][7] = std::make_pair(3, 0);
  change[0][8] = std::make_pair(0, 1);
  change[0][9] = std::make_pair(1, 1);
  change[1][2] = std::make_pair(1, 4);
  change[1][3] = std::make_pair(0, 3);
  change[1][4] = std::make_pair(0, 2);
  change[1][5] = std::make_pair(1, 4);
  change[1][6] = std::make_pair(1, 5);
  change[1][7] = std::make_pair(0, 1);
  change[1][8] = std::make_pair(0, 5);
  change[1][9] = std::make_pair(0, 4);
  change[2][3] = std::make_pair(1, 1);
  change[2][4] = std::make_pair(3, 2);
  change[2][5] = std::make_pair(2, 2);
  change[2][6] = std::make_pair(1, 2);
  change[2][7] = std::make_pair(3, 1);
  change[2][8] = std::make_pair(0, 2);
  change[2][9] = std::make_pair(1, 2);
  change[3][4] = std::make_pair(2, 1);
  change[3][5] = std::make_pair(1, 1);
  change[3][6] = std::make_pair(1, 2);
  change[3][7] = std::make_pair(2, 0);
  change[3][8] = std::make_pair(0, 2);
  change[3][9] = std::make_pair(0, 1);
  change[4][5] = std::make_pair(1, 2);
  change[4][6] = std::make_pair(1, 3);
  change[4][7] = std::make_pair(2, 1);
  change[4][8] = std::make_pair(0, 3);
  change[4][9] = std::make_pair(0, 2);
  change[5][6] = std::make_pair(0, 1);
  change[5][7] = std::make_pair(3, 1);
  change[5][8] = std::make_pair(0, 2);
  change[5][9] = std::make_pair(0, 1);
  change[6][7] = std::make_pair(4, 1);
  change[6][8] = std::make_pair(0, 1);
  change[6][9] = std::make_pair(1, 1);
  change[7][8] = std::make_pair(0, 4);
  change[7][9] = std::make_pair(0, 3);
  change[8][9] = std::make_pair(1, 0);
  for (int dx = 0; dx <= 9; dx++) {
    change[dx][dx] = std::make_pair(0, 0); 
    for (int dy = dx + 1; dy <= 9; dy++) {
      change[dy][dx] = change[dx][dy]; 
      std::swap(change[dx][dy].first, change[dx][dy].second); 
    }
  }
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> x >> y; 
    std::string s, t; 
    std::cin >> s >> t;
    std::memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int nx = 0; nx <= x; nx++) {
        for (int ny = 0; ny <= y; ny++) {
          if (dp[i][nx][ny] == 0) {
            continue; 
          }
          for (int nd = 0; nd <= 9; nd++) {
            int nextx = nx + change[s[i] - '0'][nd].first + change[t[i] - '0'][nd].first; 
            int nexty = ny + change[s[i] - '0'][nd].second + change[t[i] - '0'][nd].second; 
            if (nextx <= x && nexty <= y) {
              dp[i + 1][nextx][nexty] = 1; 
            }
          }
        }
      }
    }
    bool ans = false; 
    for (int nx = 0; nx <= x; nx++) {
      for (int ny = 0; ny <= y; ny++) {
        if (dp[n][nx][ny] == 1) {
          ans = true; 
        }
      }
    } 
    std::cout << (ans == true ? "YES" : "NO") << std::endl; 
  }
  return 0; 
}