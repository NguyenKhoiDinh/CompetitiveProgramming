#include <iostream>
#include <string> 
#include <map>
int numTest, k;
std::string s; 

int main () {
  std::cin >> numTest >> k;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    std::cin >> n >> s;
    std::map <std::string, int> cnt; 
    for (int mask = 1; mask < (1 << n); mask++) {
      std::string st = "";
      for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) > 0) {
          st += s[i]; 
        }
      }
      cnt[st]++; 
    }
    int ans = 0;
    for (std::map <std::string, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
      if (it->second == k) {
        ans++; 
      }
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}