#include <iostream>
#include <math.h>
int numTest; 
int n;
long long f, a, b;
long long t[200005];

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> f >> a >> b;
    long long sum = 0LL; 
    for (int i = 1; i <= n; i++) {
      std::cin >> t[i]; 
    }
    for (int i = 1; i <= n; i++) {
      f -= std::min((t[i] - sum) * a, b); 
      sum = t[i]; 
    }
    if (f > 0) {
      std::cout << "YES" << std::endl; 
    }
    else {
      std::cout << "NO" << std::endl;
    }
  }
  return 0; 
}