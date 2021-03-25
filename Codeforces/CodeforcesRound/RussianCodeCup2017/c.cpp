#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
const int MAX_N = 2005;
const long long MOD = 998244353;
long long dpOdd[2][MAX_N][11], dpEven[2][MAX_N][11];
long long ways[MAX_N][MAX_N];
long long fact[MAX_N];
int numTest, n, half1, half2;
string a[MAX_N];
vector <int> even, odd;

void init() {
  ways[0][0] = 1LL;
  for (int i = 0; i < MAX_N - 1; i++) {
    for (int j = 0; j < MAX_N - 1; j++) {
      if (ways[i][j] == 0) {
        continue;
      }
      (ways[i][j + 1] += ways[i][j]) %= MOD;
      (ways[i + 1][j] += (1LL * ways[i][j] * (i + 1)) % MOD) %= MOD;
    }
  }
}

void update(long long &a, long long value) {
  (a += value) %= MOD;
}

void dynamicProgramming(long long dp[MAX_N][MAX_N][11], vector <int> &a) {
  int num = (int) a.size();
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= num; j++) {
      for (int r = 0; r < 11; r++) {
        dp[i][j][r] = 0;
      }
    }
  }
  dp[0][0][0] = 1LL;
  for (int i = 0; i < num; i++) {
    int now = i & 1;
    int nxt = !now;
    for (int j = 0; j <= i + 1; j++) {
      for (int r = 0; r < 11; r++) {
        dp[nxt][j][r] = 0LL;
      }
    }
    for (int j = 0; j <= i; j++) {
      for (int r = 0; r < 11; r++) {
        if (dp[now][j][r] == 0) {
          continue;
        }
        update(dp[nxt][j + 1][(r + a[i]) % 11], dp[now][j][r]);
        update(dp[nxt][j][(r - a[i] + 11) % 11], dp[now][j][r]);
      }
    }
  }
}

void solve() {
  int numOdd = (int) odd.size();
  int numEven = (int) even.size();
  half1 = (numOdd + 1) / 2;
  half2 = numOdd - half1;
  dynamicProgramming(dpOdd, odd);
  dynamicProgramming(dpEven, even);
  long long res = 0LL;
  for (int r = 0; r < 11; r++) {
    for (int i = 0; i <= numEven; i++) {
      long long mul = 1LL;
      (mul *= dpOdd[numOdd & 1][half1][r]) %= MOD;
      (mul *= dpEven[numEven & 1][i][(11 - r) % 11]) %= MOD;
      (mul *= fact[half1]) %= MOD;
      (mul *= fact[half2]) %= MOD;
      (mul *= ways[i][half1]) %= MOD;
      (mul *= ways[numEven - i][half2 + 1]) %= MOD;
      (res += mul) %= MOD;
    }
  }
  cout << res << endl;
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  init();
  fact[0] = 1LL;
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = (1LL * fact[i - 1] * i) % MOD;
  }
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    even.clear();
    odd.clear();
    for (int i = 1; i <= n; i++) {
      string s = a[i];
      int len = (int) s.size();
      int remain = 0;
      for (int j = 0; j < len; j += 2) {
        remain += s[j] - '0';
        remain %= 11;
      }
      for (int j = 1; j < len; j += 2) {
        remain -= s[j] - '0';
        remain += 11;
        remain %= 11;
      }
      if (len % 2 == 1) {
        odd.push_back(remain);
      }
      else {
        even.push_back(remain);
      }
    }
    if (odd.empty() == true) {
      int sum = 0;
      for (int i = 0; i < (int) even.size(); i++) {
        (sum += even[i]) %= 11;
      }
      if (sum == 0) {
        cout << fact[n] << endl;
      }
      else {
        cout << 0 << endl;
      }
      continue;
    }
    solve();
  }
  return 0;
}