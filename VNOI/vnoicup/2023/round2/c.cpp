#include <iostream> 
#include <set> 
#include <algorithm> 
int n, k, numTest;
int a[200005]; 
std::multiset <int> S[200005]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k; 
    for (int r = 0; r < k; r++) {
      S[r].clear(); 
    }
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
      S[i % k].insert(a[i]);
    }
    for (int r = 1; r < k; r++) {
      int r1 = r;
      int r2 = k - r; 
      if (r2 > r1) {
        for (std::multiset <int>::iterator it = S[r2].begin(); it != S[r2].end(); it++) {
          S[r1].insert(*it); 
        }
        S[r2].clear(); 
      }
    }
    std::sort(a + 1, a + n + 1);
    bool ans = true; 
    for (int i = 1; i <= n; i++) {
      int r = i % k; 
      if (k - r < r) {
        r = k - r; 
      }
      std::multiset <int>::iterator it = S[r].find(a[i]); 
      if (it == S[r].end()) {
        ans = false;
        break;   
      }
      else {
        S[r].erase(it); 
      }
    }
    std::cout << (ans == true ? "YES" : "NO") << std::endl;  
  }
  return 0;
}