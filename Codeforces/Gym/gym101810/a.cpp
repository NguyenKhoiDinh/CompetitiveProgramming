#include <iostream> 
#include <utility> 
#include <vector> 
#include <math.h> 
#include <algorithm> 
long long sum[100005]; 
struct segment {
  int l, r; 
  long long x;
  bool operator < (const segment &other) {
    return l < other.l;
  }
};
segment a[100005]; 
int n, k, numTest; 
int L[100005], R[100005], value[100005]; 

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i].l >> a[i].r >> a[i].x;
    }
    std::sort(a + 1, a + n + 1); 
    for (int i = 1; i <= n; i++) {
      L[i] = a[i].l;
      R[i] = a[i].r; 
      value[i] = a[i].x; 
    }
    sum[0] = 0LL; 
    for (int i = 1; i <= n; i++) {
      sum[i] = sum[i - 1] + a[i].x * (a[i].r - a[i].l + 1); 
    }
    L[n + 1] = 2000000007;
    R[n + 1] = 2000000007; 
    sum[n + 1] = sum[n]; 
    long long ans = -1; 
    for (int i = 1; i <= n; i++) {
      int lim = L[i] + k - 1; 
      int pos = std::lower_bound(R + 1, R + n + 1, lim) - R; 
      long long total = sum[pos - 1] - sum[i - 1]; 
      if (lim >= L[pos]) {
        total += 1LL * (lim - L[pos] + 1) * value[pos];
      }
      ans = std::max(ans, total); 
    }
    for (int i = 1; i <= n; i++) {
      int lim = R[i] - k + 1;
      int pos = std::lower_bound(L + 1, L + n + 1, lim) - L;
      long long total = sum[i] - sum[pos - 1];
      if (lim <= R[pos - 1]) {
        total += 1LL * (R[pos - 1] - lim + 1) * value[pos - 1];
      } 
      ans = std::max(ans, total); 
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}