#include <bits/stdc++.h> 
struct point {
  long long x, y; 
};
point a[1000005]; 
int n, numTest; 

int main () {
  freopen("input.txt", "r", stdin); 
  freopen("output.txt", "w", stdout);
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i].x >> a[i].y; 
    }
    int ans = 0; 
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, n);
    for (int steps = 1; steps <= 100; steps++) {
      int i = distribution(generator);
      int j;
      while (true) {
        j = distribution(generator); 
        if (j != i) {
          break; 
        }
      } 
      int numb = 2; 
      long long vx = a[j].x - a[i].x; 
      long long vy = a[j].y - a[i].y; 
      for (int k = 1; k <= n; k++) {
        if (k != i && k != j) {
          long long vkx = a[k].x - a[i].x; 
          long long vky = a[k].y - a[i].y; 
          if (vx * vky == vy * vkx) {
            numb++;   
          }
        }
      }
      ans = std::max(ans, numb); 
    }     
    std::cout << n - ans << std::endl; 
    std::cerr << "TEST CASE #" << testCase << " DONE" << std::endl; 
  } 
  return 0; 
}