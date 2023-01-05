#include <iostream> 
#include <math.h>
#include <fstream>
int numTest; 
const long long inf = 100000000000000007LL;
long long dp[12][12][(1 << 10) + 5][22]; 
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
struct element {
  char oper;
  int value;
};
element save[4];
struct customer {
  int x, y;
  int cost; 
};
customer a[15]; 
int haveCustomer[12][12];
int n, m, p, startx, starty; 

void update(long long &a, long long b) {
  a = std::max(a, b); 
}

long long calc(int step, long long value) {
  if (save[step].oper == '+') {
    return value + save[step].value; 
  }
  else if (save[step].oper == '-') {
    return value - save[step].value; 
  }
  else if (save[step].oper == '*') {
    return value * save[step].value; 
  }
  return (long long) std::floor(1.0 * value / (1.0 * save[step].value)); 
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> n >> p >> m >> startx >> starty;
    for (int i = 0; i < 4; i++) {
      std::cin >> save[i].oper >> save[i].value;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        haveCustomer[i][j] = -1; 
      }
    }
    for (int i = 0; i < p; i++) {
      std::cin >> a[i].x >> a[i].y >> a[i].cost;
      haveCustomer[a[i].x][a[i].y] = i; 
    }
    for (int x = 1; x <= n; x++) {
      for (int y = 1; y <= n; y++) {
        for (int mask = 0; mask < (1 << p); mask++) {
          for (int j = 0; j <= m; j++) {
            dp[x][y][mask][j] = -inf; 
          }
        }
      }
    }
    dp[startx][starty][0][0] = 0; 
    for (int j = 0; j < m; j++) {
      for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
          for (int mask = 0; mask < (1 << p); mask++) {
            if (dp[x][y][mask][j] == -inf) {
              continue; 
            }
            long long value = dp[x][y][mask][j]; 
            update(dp[x][y][mask][j + 1], value);
            for (int i = 0; i < 4; i++) {
              int nextx = x + dx[i];
              int nexty = y + dy[i]; 
              if (nextx >= 1 && nextx <= n && nexty >= 1 && nexty <= n) {
                long long nextValue = calc(i, value);
                int nextmask = mask;
                update(dp[nextx][nexty][mask][j + 1], nextValue);
                if (haveCustomer[nextx][nexty] != -1) {
                  int id = haveCustomer[nextx][nexty];
                  if ((mask & (1 << id)) == 0) {
                    nextmask = mask | (1 << id); 
                    update(dp[nextx][nexty][nextmask][j + 1], nextValue + a[id].cost);
                  }
                } 
              }
            } 
          }
        }
      }
    }
    long long ans = -inf; 
    for (int x = 1; x <= n; x++) {
      for (int y = 1; y <= n; y++) {
        update(ans, dp[x][y][(1 << p) - 1][m]);
      }
    }
    if (ans == -inf) {
      std::cout << "IMPOSSIBLE";
    }
    else {
      std::cout << ans; 
    }
    std::cout << std::endl; 
  }
  return 0; 
}