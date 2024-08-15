#include <iostream>
#include <utility> 
#include <cstring> 
const long long mod = 998244353LL; 
long long f[2005][2005][2]; 
int n, k; 
std::pair <int, int> save[2005]; 
int pos[2005]; 

int main () {
  int numTest;
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k;
    for (int i = 0; i <= n; i++) {
      pos[i] = -1; 
    }
    for (int i = 1; i <= k; i++) {
      std::cin >> save[i].first >> save[i].second;
      pos[save[i].first] = 0;
      pos[save[i].second] = 1;  
    }
    std::memset(f, 0, sizeof(f)); 
    f[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int freeOpen = 0; freeOpen <= i; freeOpen++) {
        for (int last = 0; last <= 1; last++) {
          if (f[i][freeOpen][last] == 0) {
            continue; 
          }
          if (pos[i + 1] <= 0) {
            (f[i + 1][freeOpen + 1][(pos[i + 1] == 0 ? 0 : last)] += f[i][freeOpen][last]) %= mod; 
            if (freeOpen > 0) {
              (f[i + 1][freeOpen - 1][(pos[i + 1] == 0 ? 1 : last)] += f[i][freeOpen][last]) %= mod; 
            }
          }
          else {
            if (last == 0 && freeOpen > 0) {
              (f[i + 1][freeOpen - 1][last] += f[i][freeOpen][last]) %= mod; 
            }
            if (last == 1) {
              (f[i + 1][freeOpen + 1][last] += f[i][freeOpen][last]) %= mod;
            }
          }
        }
      }
    }
    long long ans = f[n][0][0];
    (ans += f[n][0][1]) %= mod;
    std::cout << ans << std::endl;   
  }
  return 0; 
}