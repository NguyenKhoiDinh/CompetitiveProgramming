#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 305;
const long long MOD = 1000000007;
long long dp[MAX_N][MAX_N][2][2];
int n, k;
int a[MAX_N];
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
  (v *= numb) %= MOD;
  if (newSolved == 1 && solved == 0) {
    int numbSolved = easyRead + hardRead + read - k;
    if (easyRead + hardRead + read == n) {
      numbSolved = max(numbSolved, pos - 1);
    }
    (v *= (n - numbSolved)) %= MOD;
  }
  (dp[easyRead][hardRead][read][newSolved] += v) %= MOD;
}

void DynamicProgramming(int pos) {
  int totalEasy = pos - 1;
  int totalHard = n - pos;
  for (int easyRead = 0; easyRead < MAX_N; easyRead++) {
    for (int hardRead = 0; hardRead < MAX_N; hardRead++) {
      for (int read = 0; read <= 1; read++) {
        for (int solved = 0; solved <= 1; solved++) {
          dp[easyRead][hardRead][read][solved] = 0;
        }
      }
    }
  }
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
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    DynamicProgramming(i);
    (ans += (1LL * a[i] * dp[i - 1][n - i][1][1]) % MOD) %= MOD;
  }
  printf("%lld", ans);
  return 0;
}