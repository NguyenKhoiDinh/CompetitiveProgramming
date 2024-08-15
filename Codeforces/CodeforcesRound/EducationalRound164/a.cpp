#include <iostream> 
#include <vector>
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector <int> cnt(m, 0);
    for (int i = 0; i < n; i++) {
      cnt[i % m]++; 
    }
    int maxi = cnt[0];
    std::cout << ((k < n - maxi && m > 1) ? "YES" : "NO") << std::endl;    
  }
  return 0; 
}