#include <iostream> 
#include <algorithm>
const long long mod = 998244353LL; 
int numTest; 
long long f[5005][5005][2]; 
int n;                           
int a[5005]; 

int main () {
  std::cin >> n;
  int total = 0; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    total += a[i];  
  }
  std::sort(a + 1, a + n + 1); 
  f[0][0][0] = 1LL;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= total; j++) {
      for (int state = 0; state <= 1; state++) {
        if (f[i][j][state] == 0) {
          continue; 
        }
        (f[i + 1][j][0] += f[i][j][state]) %= mod;
        (f[i + 1][j + a[i + 1]][1] += f[i][j][state]) %= mod;  
      }
    }
  }
  long long ans = 0LL;
  for (int i = 1; i <= n; i++) {
    for (int numb = 1; numb <= total; numb++) {
      if (f[i][numb][1] == 0) {
        continue; 
      }
      int value = numb;
      if (a[i] >= value - a[i]) {
        value = a[i]; 
      }
      else {
        value = (numb + 1) / 2; 
      }
      (ans += ((long long) value * f[i][numb][1]) % mod) %= mod; 
    }
  }
  std::cout << ans << std::endl;
  return 0; 
}