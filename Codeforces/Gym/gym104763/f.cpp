#include <iostream>
#include <vector> 
#include <algorithm>
#include <math.h> 
long long N; 

int main () {
  std::cin >> N;
  std::vector <long long> ans; 
  for (long long base = 2; base * base <= N; base++) {
    std::vector <long long> dig; 
    long long tmp = N; 
    while (tmp > 0) {
      dig.push_back(tmp % base); 
      tmp /= base; 
    }
    int l = 0;
    int r = (int) dig.size() - 1; 
    bool check = true; 
    while (l <= r) {
      if (dig[l] != dig[r]) {
        check = false;
        break;   
      }
      l++;
      r--;
    }
    if (check == true) {
      ans.push_back(base);
    }
  }
  for (long long x = 1; x * x <= N; x++) {
    if (N % x != 0) {
      continue; 
    }
    long long base = N / x - 1; 
    if (base > 1) {
      ans.push_back(base); 
    }
  }       
  std::sort(ans.begin(), ans.end());
  if (ans.empty() == true) {
    std::cout << "*"; 
  } 
  else {
    std::cout << ans[0] << ' '; 
    for (int i = 1; i < (int) ans.size(); i++) {
      if (ans[i] != ans[i - 1]) {
        std::cout << ans[i] << ' '; 
      }
    }
  }
  return 0; 
}