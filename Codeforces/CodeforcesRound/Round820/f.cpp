#include <iostream>
#include <string>
#include <set> 
int numTest; 
std::set <int> S[9];
int sum[200005];
std::string s; 
int n, w, numQuery; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> s;
    n = (int) s.size();
    std::cin >> w >> numQuery;
    for (int i = 1; i <= n; i++) {
      sum[i] = (sum[i - 1] + s[i - 1] - '0') % 9; 
    }
    for (int r = 0; r < 9; r++) {
      S[r].clear();
    }
    for (int i = 1; i + w - 1 <= n; i++) {
      S[(sum[i + w - 1] - sum[i - 1] + 9) % 9].insert(i); 
    }
    for (int query = 1; query <= numQuery; query++) {
      int l, r, k;
      int resL1 = 200005, resL2 = 200005;
      std::cin >> l >> r >> k;
      int value = (sum[r] - sum[l - 1] + 9) % 9; 
      for (int r1 = 0; r1 < 9; r1++) {
        int remainder = (r1 * value) % 9; 
        int r2 = (9 + k - remainder) % 9;
        std::set <int>::iterator it1 = S[r1].lower_bound(1);
        if (it1 != S[r1].end()) {
          int l1 = *it1; 
          if (r1 == r2) {
            S[r1].erase(it1); 
          }
          std::set <int>::iterator it2 = S[r2].lower_bound(1);
          if (it2 != S[r2].end()) {
            int l2 = *it2;
            if (resL1 > l1) {
              resL1 = l1;
              resL2 = l2; 
            }   
          }
          if (r1 == r2) {
            S[r1].insert(l1); 
          }
        } 
      }
      std::cout << (resL1 == 200005 ? -1 : resL1) << ' ' << (resL2 == 200005 ? -1 : resL2) << std::endl; 
    }
  }
  return 0; 
}