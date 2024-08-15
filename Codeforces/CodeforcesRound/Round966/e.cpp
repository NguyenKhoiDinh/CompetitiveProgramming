#include <iostream> 
#include <math.h> 
#include <vector>
#include <algorithm> 
int numTest; 
bool compare(long long a, long long b) {
  return a > b; 
}
int n, m, k; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m >> k;
    int g; 
    std::cin >> g; 
    std::vector <long long> a, b; 
    a.resize(g); 
    for (int i = 0; i < g; i++) {
      std::cin >> a[i];     
    }       
    std::sort(a.begin(), a.end(), compare); 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int lo = std::max(0, i - k + 1);
        int hi = std::min(n - 1, i + k - 1);
        int w = (hi - lo + 1 - k + 1);
        lo = std::max(0, j - k + 1);
        hi = std::min(m - 1, j + k - 1);
        int h = (hi - lo + 1 - k + 1);
        b.push_back((long long) w * h);    
      }
    }
    std::sort(b.begin(), b.end(), compare); 
    long long ans = 0LL; 
    for (int i = 0; i < g; i++) {
      ans += a[i] * b[i]; 
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}