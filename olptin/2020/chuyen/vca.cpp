#include <iostream>
#include <string>
#include <math.h>
int cnt[26]; 
std::string s; 
int n, k; 

int main () {
  std::cin >> k; 
  std::cin >> s; 
  n = (int) s.size(); 
  int ans = n + 1; 
  int p = 0; 
  for (int i = 0; i < n; i++) {
    cnt[s[i] - 'A']++; 
    while (p <= i) {
      if (cnt[s[p] - 'A'] > k) {
        cnt[s[p] - 'A']--;
        p++; 
      }
      else {
        break; 
      }
    }
    if (cnt[0] >= k && cnt[2] >= k && cnt['V' - 'A'] >= k) {
      ans = std::min(ans, i - p + 1 - 3 * k);   
    }
  }
  if (ans == n + 1) {
    std::cout << -1; 
  }
  else {
    std::cout << ans;
  }
  return 0; 
}