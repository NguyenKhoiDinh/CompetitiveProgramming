#include <iostream> 
#include <bitset> 
std::bitset <2000005> f[2]; 
int n; 
int a[2005]; 
int sum = 0; 

int main () {
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    sum += a[i];  
  }
  f[0].set(0, 1); 
  for (int i = 0; i < n; i++) {
    int now = i % 2;
    int nxt = !now; 
    f[nxt].reset(); 
    f[nxt] |= f[now]; 
    f[nxt] |= (f[now] << a[i]); 
  }
  int ans = 0; 
  for (int i = 0; i * 2 <= sum; i++) {
    if (f[n % 2][i] == 1) {
      ans++;
    }
  } 
  std::cout << ans; 
  return 0;
}