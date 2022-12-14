#include <iostream> 
int numTest;
int n;
int a[100005];
int numQuery;  

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> numQuery;
    int cntOdd = 0; 
    int cntEven = 0;
    long long ans = 0;  
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
      ans += a[i]; 
      if (a[i] % 2 == 0) {
        cntEven++; 
      } 
      else {
        cntOdd++; 
      }
    }
    for (int query = 1; query <= numQuery; query++) {
      int type, x;
      std::cin >> type >> x; 
      if (type == 0) {
        ans += 1LL * cntEven * x;
        std::cout << ans << std::endl;
        if (x % 2 == 1) {
          cntOdd += cntEven; 
          cntEven = 0; 
        } 
      }
      else {
        ans += 1LL * cntOdd * x; 
        std::cout << ans << std::endl; 
        if (x % 2 == 1) {
          cntEven += cntOdd;
          cntOdd = 0; 
        }
      }
    }  
  }
  return 0; 
}