#include <iostream> 
#include <utility> 
#include <math.h> 
#include <algorithm>
int n, m; 
std::pair <long long, long long> a[100005];
long long maxSuffix[100005]; 
long long prefixSum[100005]; 
long long ans = -1;

int main () {
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    std::cin >> a[i].first >> a[i].second;
  }
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    prefixSum[i] = a[i].first;
    prefixSum[i] += prefixSum[i - 1]; 
  } 
  for (int i = n; i >= 1; i--) {
    maxSuffix[i] = a[i].second;
    maxSuffix[i] = std::max(maxSuffix[i], maxSuffix[i + 1]); 
  }
  for (int i = 1; i <= n; i++) {
    ans = std::max(ans, prefixSum[i] + 1LL * (n - i) * maxSuffix[i]);  
  }
  std::cout << ans;
  return 0; 
}