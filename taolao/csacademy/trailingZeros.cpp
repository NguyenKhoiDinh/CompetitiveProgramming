#include <iostream> 

int main () {
  int ans = -1; 
  int lo = 0;
  int hi = 1000000; 
  while (lo <= hi) {
    int mid = (lo + hi) / 2; 
    std::cout << "Q " << mid << std::endl;
    int ok;
    std::cin >> ok;
    if (ok == 0) { 
      hi = mid - 1; 
    } 
    else {
      ans = mid;
      lo = mid + 1; 
    }
  }
  for (int i = 0; i <= 5 * ans; i++) {
    int total = 0;
    for (int p = 5; p <= 5 * ans; p *= 5) {
      total += i / p; 
    }
    if (total == ans) {
      std::cout << "A " << i << std::endl;
      return 0;
    }
  } 
  return 0; 
}