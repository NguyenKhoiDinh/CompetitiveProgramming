#include <iostream> 
#include <math.h> 
#include <vector> 
#include <algorithm>
long long a[200005]; 
std::vector <int> save; 
int n;

int main () {    
  std::cin >> n; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  for (int i = 1; i < n; i++) {
    long long value = a[i] * a[i + 1];
    value /= std::__gcd(a[i], a[i + 1]);
    long long sqrtValue = (long long) std::sqrt(value);
    if (sqrtValue * sqrtValue != value) {
      save.push_back(i); 
    } 
  }
  int ans = 0; 
  for (int i = 0; i < (int) save.size(); i++) {
    ans++; 
    if (i < (int) save.size() - 1 && save[i] + 1 == save[i + 1]) {
      i++;
    }
  }
  std::cout << ans;
  return 0; 
}