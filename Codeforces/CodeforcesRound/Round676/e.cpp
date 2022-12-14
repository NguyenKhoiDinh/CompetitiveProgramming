#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 200005;
const long long inf = -MAX_N * 1000000007LL;
long long dp[MAX_N][3][2][2];
int a[MAX_N];
int n; 

void update(long long &a, long long b) {
  a = max(a, b);
}

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];  
  }
  if (n == 1) {
    cout << a[1];
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int r = 0; r < 3; r++) {
      for (int valid = 0; valid <= 1; valid++) {
        for (int sign = 0; sign <= 1; sign++) {
          dp[i][r][valid][sign] = inf;
        }
      }
    }
  }
  dp[1][0][0][0] = a[1];
  dp[1][1][0][1] = -a[1];
  for (int i = 1; i < n; i++) {
    for (int r = 0; r < 3; r++) {
      for (int valid = 0; valid <= 1; valid++) {
        for (int sign = 0; sign <= 1; sign++) {
          if (dp[i][r][valid][sign] == inf) {
            continue;
          }
          for (int nextSign = 0; nextSign <= 1; nextSign++) {
            update(dp[i + 1][(r + nextSign) % 3][valid == 1 || (valid == 0 && sign == nextSign)][nextSign], dp[i][r][valid][sign] + (nextSign == 0 ? a[i + 1] : -a[i + 1]));
          }
        }
      }
    }
  }
  cout << max(dp[n][(4 - n % 3) % 3][1][0], dp[n][(4 - n % 3) % 3][1][1]);
  return 0; 
}