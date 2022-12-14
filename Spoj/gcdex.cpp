#include <iostream> 

using namespace std;
const int MAX_N = 1000005; 
int mu[MAX_N]; 
long long f[MAX_N]; 
long long sumf[MAX_N]; 
int numTest; 

void init() {
  mu[1] = 1; 
  for (int i = 1; i <= 1000000; i++) {
    for (int j = 2 * i; j <= 1000000; j += i) {
      mu[j] -= mu[i]; 
    }
  }
  for (int i = 1; i <= 1000000; i++) {
    for (int j = i; j <= 1000000; j += i) {
      f[j] += 1LL * i * mu[j / i]; 
    }
  }
  for (int i = 1; i <= 1000000; i++) {
    sumf[i] = sumf[i - 1] + f[i]; 
  }
}

int main () {
  init(); 
  while (true) {
    int n;
    cin >> n; 
    if (n == 0) {
      break; 
    }
    long long ans = 0LL; 
    for (int i = 1, j; i <= n; i = j + 1) {
      j = n / (n / i); 
      ans += 1LL * (n / i) * (n / i - 1) / 2 * (sumf[j] - sumf[i - 1]); 
    } 
    cout << ans << endl; 
  }
  return 0;  
}