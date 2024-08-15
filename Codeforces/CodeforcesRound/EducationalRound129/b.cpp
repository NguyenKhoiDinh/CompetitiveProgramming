#include <iostream>
int numTest; 
int a[200005], b[200005]; 
int n; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    int m; 
    std::cin >> m;
    int ans = 0; 
    for (int i = 0; i < m; i++) {
      int x;
      std::cin >> x;
      (ans += x) %= n;
    }
    std::cout << a[ans] << std::endl;
  }
  return 0; 
}