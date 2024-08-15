#include <iostream> 
int n, p;
long long mod; 
long long f[505][535]; 

int main () {
  std::cin >> n >> p >> mod;
  f[0][p] = 1LL; 
  for (int i = 1; i <= n - p; i++) {
    for (int j = 0; j + i <= n - p; j++) {
      for (int sumXor = 0; sumXor <= 511; sumXor++) {
        (f[i + j][sumXor ^ i] += f[j][sumXor]) %= mod;
      }
    } 
  }
  std::cout << f[n - p][0]; 
  return 0; 
}