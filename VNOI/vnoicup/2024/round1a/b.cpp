#include <iostream>
int n;
long long a[200005]; 
long long b[200005]; 

int main () {
  int numTest;
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }  
    for (int i = 2; i <= n; i++) {
      a[i] += a[i - 1] / 2; 
      a[i - 1] %= 2; 
    }
    for (int i = 1; i <= n; i++) {
      std::cin >> b[i]; 
    }
    long long numb = 0; 
    bool ok = true; 
    for (int i = n; i >= 1; i--) {
      numb *= 2LL; 
      if (a[i] + numb < b[i]) {
        ok = false;
        break; 
      }  
      if (numb >= 200000000000007LL) {
        break; 
      }
      numb += a[i] - b[i]; 
    }
    std::cout << (ok == true ? "YES" : "NO") << std::endl;
  }
  return 0; 
}