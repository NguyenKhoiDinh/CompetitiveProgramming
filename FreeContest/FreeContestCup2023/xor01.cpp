#include <iostream>
int n;
int cnt[200005]; 
long long ans = 0LL; 

int main () {
  std::cin >> n; 
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x; 
    ans += cnt[x]; 
    ans += cnt[1 ^ x]; 
    cnt[x]++;
  }
  std::cout << ans;
  return 0; 
}