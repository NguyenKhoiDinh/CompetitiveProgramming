#include <iostream>
#include <string> 
int numTest; 
int cnt[4000005]; 
bool ok[4000005]; 
std::string s; 
int n, q;  

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> n;
    std::cin >> s; 
    for (int i = 0; i < n; i++) {
      cnt[i + 1] = 0;
      ok[i + 1] = false;
    }
    std::cin >> q; 
    for (int i = 1; i <= q; i++) {
      int x; 
      std::cin >> x; 
      ok[x] = true; 
      cnt[x] ^= 1; 
    }
    for (int i = n; i >= 1; i--) {
      if (ok[i] == false || cnt[i] == 0) {
        continue;
      }
      for (int j = 2 * i; j <= n; j += i) {
        cnt[j] ^= cnt[i]; 
      }
    }
    for (int i = 1; i <= n; i++) {
      cnt[i] ^= (s[i - 1] - '0'); 
    }
    int ans = 0; 
    for (int i = 1; i <= n; i++) {
      if (cnt[i] == 1) {
        ans++; 
        for (int j = i; j <= n; j += i) {
          cnt[j] ^= 1; 
        }
      }
    }                      
    std::cout << ans << std::endl;
    std::cerr << "Case #" << testCase << ": DONE" << std::endl;
  } 
  return 0; 
}