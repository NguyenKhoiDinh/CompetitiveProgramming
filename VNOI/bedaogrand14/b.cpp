#include <iostream>
long long a[100005], b[100005];
int n, m; 

int main () {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> b[i];
  }
  long long ans = 0LL; 
  for (int bit = 0; bit <= 29; bit++) {
    int cntOne = 0;
    for (int i = 1; i <= n; i++) {
      if ((a[i] & (1 << bit)) > 0) {
        cntOne++; 
      }
    }
    int cntZero = 0;
    for (int i = 1; i <= m; i++) {
      if ((b[i] & (1 << bit)) == 0) {
        cntZero++; 
      }
    }
    ans += 1LL * cntOne * cntZero * (1 << bit); 
  }
  std::cout << ans;
  return 0; 
}