#include <iostream>
int a[200005]; 
int cnt[200005]; 
int n, numTest; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      cnt[i] = 0;
    }
    long long ans = 0LL;
    int numDiff = 0; 
    int l = 1; 
    for (int i = 1; i <= n; i++) {
      cnt[a[i]]++;
      if (cnt[a[i]] == 1) {
        numDiff++; 
      }  
      while (numDiff < i - l + 1) {
        cnt[a[l]]--;
        if (cnt[a[l]] == 0) {
          numDiff--;
        }
        l++; 
      }
      ans += numDiff;
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}