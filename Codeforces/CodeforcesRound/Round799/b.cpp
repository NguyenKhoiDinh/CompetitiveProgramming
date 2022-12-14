#include <iostream> 
#include <cstring> 
int numTest;
int a[55]; 
int n; 
int cnt[10005]; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::memset(cnt, 0, sizeof(cnt)); 
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
      cnt[a[i]]++; 
    }
    int total = 0; 
    for (int i = 1; i <= 10000; i++) {
      if (cnt[i] > 0) {
        total += cnt[i] - 1; 
      }
    }
    if (total % 2 == 1) {
      std::cout << n - total - 1 << std::endl; 
    }
    else {
      std::cout << n - total << std::endl; 
    }
  }
  return 0;
}