#include <iostream> 
#include <cstring>
#include <math.h> 
int n, m, k; 
int a[10005]; 
int cnt[10005], cntBigger[10005]; 
int ans[10005]; 

int main () {
  std::cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    std::cin >> a[i]; 
  }
  for (int i = 1; i <= m; i++) {
    std::memset(cnt, 0, sizeof(cnt));
    std::memset(cntBigger, 0, sizeof(cntBigger));
    for (int j = i; j <= std::min(m, i + k - 1); j++) {
      ans[a[j]] = std::max(ans[a[j]], cntBigger[cnt[a[j]] + 1] + 1);
      cnt[a[j]]++;
      cntBigger[cnt[a[j]]]++;     
    }
    for (int j = 1; j <= n; j++) {
      ans[j] = std::max(ans[j], cntBigger[cnt[j] + 1] + 1); 
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << ' ';
  }
  return 0; 
}