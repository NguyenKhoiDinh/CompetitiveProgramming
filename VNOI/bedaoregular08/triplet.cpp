#include <iostream> 

int main () {
  int n, k; 
  std::cin >> n >> k;
  if (k % 2 == 1) {
    long long cnt = n / k;
    std::cout << cnt * cnt * cnt; 
  }
  else {
    long long cnt1 = n / k;     
    long long cnt2 = (n - k / 2) / k + 1; 
    std::cout << cnt1 * cnt1 * cnt1 + cnt2 * cnt2 * cnt2; 
  }
  return 0; 
}