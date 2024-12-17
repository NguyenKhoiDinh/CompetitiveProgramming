#include <iostream> 
#include <algorithm> 
#include <math.h> 
int numTest; 
int a[200005];
int n;         

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    long long sum = 0LL; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
      sum += a[i]; 
    }  
    std::sort(a + 1, a + n + 1); 
    if (n <= 2) {
      std::cout << -1 << std::endl; 
    }
    else {
      std::cout << std::max(0LL, 2LL * n * a[n / 2 + 1] - sum + 1) << std::endl;
    }
  }
  return 0; 
}


                               
