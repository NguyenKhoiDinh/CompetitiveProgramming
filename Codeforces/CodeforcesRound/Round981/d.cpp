#include <iostream> 
#include <map> 
#include <math.h> 
int f[100005]; 
int a[100005]; 
long long sum[100005]; 
int n; 
std::map <long long, int> lastPosition; 

int main () {
  int numTest;
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    lastPosition.clear();
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
      sum[i] = sum[i - 1] + a[i]; 
    } 
    for (int i = 0; i <= n; i++) {
      f[i] = -1; 
    }
    f[0] = 0; 
    lastPosition[0] = 0; 
    for (int i = 1; i <= n; i++) {
      f[i] = f[i - 1]; 
      if (lastPosition.find(sum[i]) != lastPosition.end()) {
        f[i] = std::max(f[i], f[lastPosition[sum[i]]] + 1); 
      }
      lastPosition[sum[i]] = i;
    }
    std::cout << f[n] << std::endl;
  }
  return 0; 
}