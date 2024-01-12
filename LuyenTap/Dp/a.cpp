#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
const int mod = 1000000007; 
int n; 
int a[100005]; 
std::vector <int> group[73];
int ways[100005][1 << 4][2];
int f[72][1 << 4];  
int prime[4] = {2, 3, 5, 7};

void createWaysTable(int value) {
  std::memset(ways, 0, sizeof(ways));
  int sizeGroup = (int) group[value].size(); 
  ways[0][0][0] = 1;
  for (int i = 0; i < sizeGroup; i++) {
    for (int mask = 0; mask < (1 << 4); mask++) {
      for (int even = 0; even <= 1; even++) {
        if (ways[i][mask][even] == 0) {
          continue; 
        }
        (ways[i + 1][mask][even] += ways[i][mask][even]) %= mod; 
        (ways[i + 1][mask ^ group[value][i]][(even + 1) % 2] += ways[i][mask][even]) %= mod; 
      }
    }
  }  
} 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  for (int i = 1; i <= n; i++) {
    int value = a[i];
    int mask = 0;
    for (int p = 0; p < 4; p++) {
      int cnt = 0; 
      while (value % prime[p] == 0) {
        cnt++;
        value /= prime[p]; 
      }
      if (cnt % 2 == 1) {
        mask |= (1 << p); 
      }
    }
    group[value].push_back(mask);   
  }
  f[0][0] = 1;
  for (int value = 0; value < 70; value++) {
    createWaysTable(value + 1);
    int sizeGroup = (int) group[value + 1].size();  
    for (int mask = 0; mask < (1 << 4); mask++) {
      if (f[value][mask] == 0) {
        continue; 
      }
      for (int nextmask = 0; nextmask < (1 << 4); nextmask++) {
        int numbWays = ways[sizeGroup][nextmask][0];
        if (value == 0) {
          (numbWays += ways[sizeGroup][nextmask][1]) %= mod;   
        }
        (f[value + 1][mask ^ nextmask] += (1LL * numbWays * f[value][mask]) % mod) %= mod; 
      } 
    }
  }
  int ans = f[70][0];
  (ans += mod - 1) %= mod;
  std::cout << ans;                                             
  return 0; 
}