#include <iostream> 
bool flag[60]; 

int main () {
  int numTest; 
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    long long s;
    int n; 
    std::cin >> s >> n; 
    for (int i = 0; i < n; i++) {
      flag[i] = false; 
    }
    if (s % 2 == 0 || s > ((1LL << (long long) n) - 1)) {
      std::cout << -1 << std::endl; 
      continue; 
    }
    long long total = s + ((1LL << (long long) n) - 1); 
    long long half = total / 2; 
    for (long long i = 0; i < n; i++) {
      if ((half & (1LL << i)) > 0) {
        flag[i] = true; 
      }
      else {
        flag[i] = false; 
      }
    }
    long long ans = 0LL; 
    bool isLeft = true;
    for (long long i = n; i >= 1; i--) {
      if (isLeft == flag[i - 1]) {
        continue; 
      }
      ans += (1LL << i) - 2;
      ans++;
      if (i > 1 && flag[i - 2] == true) {
        isLeft = true; 
      } 
      else {
        isLeft = false; 
      }
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}