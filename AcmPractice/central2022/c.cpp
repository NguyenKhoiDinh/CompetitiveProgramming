#include <iostream>
#include <utility>
#include <algorithm>
int n, k;
std::pair <int, int> a[100005]; 
long long fw[100005][12]; 
long long dp[100005][12];

void update(int index, int j, long long value) {
  for (; index <= 100000; index += index & -index) {
    fw[index][j] += value; 
  }
}

long long get(int index, int j) {
  long long ret = 0LL; 
  for (; index > 0; index -= index & -index) {
    ret += fw[index][j]; 
  }
  return ret; 
}

int main () {
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first >> a[i].second; 
  }
  std::sort(a + 1, a + n + 1); 
  for (int i = 1; i <= n; i++) {
    dp[i][1] = 1; 
  }
  for (int j = 2; j <= k; j++) {
    for (int i = 1; i <= n; i++) {
      dp[i][j] = get(a[i].second - 1, j - 1);
      update(a[i].second, j - 1, dp[i][j - 1]);     
    }
  }
  long long ans = 0LL;
  for (int i = 1; i <= n; i++) {
    ans += dp[i][k]; 
  }
  std::cout << ans;
  return 0; 
}