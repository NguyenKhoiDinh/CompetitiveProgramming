#include <iostream>
int numTest; 
int cnt[22]; 
int n; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    for (int i = 1; i <= 20; i++) {
      cnt[i] = 0;
    }  
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      int x;
      std::cin >> x;
      cnt[x]++; 
    }
    int ans = 0;
    for (int x = 1; x <= 20; x++) {
      ans += cnt[x] / 2;
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}