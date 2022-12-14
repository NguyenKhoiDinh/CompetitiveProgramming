#include <bits/stdc++.h>
                      
const long long mod = 1000000007;
long long dp[305][305][2][2];
int n, k;
int a[305];
long long ans = 0;

void update(int pos, int easyRead, int hardRead, int read, int solved, long long val, int numb) {
  int newSolved = solved;
  if (easyRead + hardRead + read >= k) {
    int numbSolved = easyRead + hardRead + read - k;
    if (read == 1 && numbSolved >= easyRead) {
      newSolved = 1;
    }
  }
  if (easyRead + hardRead + read == n) {
    newSolved = 1;
  }
  long long v = val;
  (v *= numb) %= mod;
  if (newSolved == 1 && solved == 0) {
    int numbSolved = easyRead + hardRead + read - k;
    if (easyRead + hardRead + read == n) {
      numbSolved = std::max(numbSolved, pos - 1);
    }
    (v *= (n - numbSolved)) %= mod;
  }
  (dp[easyRead][hardRead][read][newSolved] += v) %= mod;
}

void dynamicProgramming(int pos) {
  int totalEasy = pos - 1;
  int totalHard = n - pos;
  std::memset(dp, 0, sizeof(dp)); 
  dp[0][0][0][0] = 1;
  for (int easyRead = 0; easyRead <= totalEasy; easyRead++) {
    for (int hardRead = 0; hardRead <= totalHard; hardRead++) {
      for (int read = 0; read <= 1; read++) {
        for (int solved = 0; solved <= 1; solved++) {
          if (dp[easyRead][hardRead][read][solved] == 0) {
            continue;
          }
          long long val = dp[easyRead][hardRead][read][solved];
          if (easyRead < totalEasy) {
            update(pos, easyRead + 1, hardRead, read, solved, val, totalEasy - easyRead);
          }
          if (hardRead < totalHard) {
            update(pos, easyRead, hardRead + 1, read, solved, val, totalHard - hardRead);
          }
          if (read == 0) {
            update(pos, easyRead, hardRead, 1, solved, val, 1);
          }
        }
      }
    }
  }
}

int main () {
  std::cin >> n >> k; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    dynamicProgramming(i);
    (ans += (1LL * a[i] * dp[i - 1][n - i][1][1]) % mod) %= mod;
  }
  std::cout << ans;
  return 0;
}