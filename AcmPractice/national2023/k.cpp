#include <iostream>
#include <iomanip>
#include <string>
#include <utility>                     
#include <vector>
#include <cstring>
const int MAX_BIT = 20;
std::pair <std::string, std::string> a[MAX_BIT]; 
long long f_prefix[(1 << MAX_BIT) + 5], f_suffix[(1 << MAX_BIT) + 5];
int n, numTest;     
bool adj[20][20];
double ans[20][20]; 
std::vector <int> listBit0[(1 << MAX_BIT) + 5], listBit1[(1 << MAX_BIT) + 5]; 

void createPrefix() {
  for (int mask = 0; mask < (1 << n); mask++) {
    f_prefix[mask] = 0LL;
  }
  f_prefix[0] = 1LL; 
  for (int mask = 0; mask < (1 << n) - 1; mask++) {
    if (f_prefix[mask] == 0) {
      continue;   
    }
    int numb = (int) __builtin_popcount(mask); 
    for (int i = 0; i < (int) listBit0[mask].size(); i++) {
      int u = listBit0[mask][i];
      if (u >= n) {
        break;
      }
      if (adj[numb][u] == true) {
        f_prefix[mask ^ (1 << u)] += f_prefix[mask]; 
      }
    }
  }
}

void createSuffix() {                          
  for (int mask = 0; mask < (1 << n); mask++) {
    f_suffix[mask] = 0LL;
  }
  f_suffix[0] = 1LL; 
  for (int mask = 0; mask < (1 << n) - 1; mask++) {
    if (f_suffix[mask] == 0) {
      continue;
    }
    int numb = (int) __builtin_popcount(mask); 
    for (int i = 0; i < (int) listBit0[mask].size(); i++) {
      int u = listBit0[mask][i];
      if (u >= n) {
        break; 
      }
      if (adj[n - 1 - numb][u] == true) {
        f_suffix[mask ^ (1 << u)] += f_suffix[mask]; 
      }
    }
  }                                                
}

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  for (int mask = 0; mask < (1 << MAX_BIT); mask++) {
    for (int i = 0; i < MAX_BIT; i++) {
      int bit = (mask & (1 << i)) > 0; 
      if (bit == 1) {
        listBit1[mask].push_back(i);
      }
      else {
        listBit0[mask].push_back(i); 
      }
    }                   
  }
  while (true) {
    std::cin >> n;
    if (n == 0) {
      return 0;
    }
    for (int i = 0; i < n; i++) {
      std::cin >> a[i].first >> a[i].second; 
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        adj[i][j] = false;
        ans[i][j] = 0.0;
      }
    }  
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i != j && a[i].first != a[j].second) {
          adj[i][j] = true; 
        }
      }
    }
    createPrefix();
    createSuffix(); 
    long long omega = f_prefix[(1 << n) - 1]; 
    for (int mask = 1; mask < (1 << n); mask++) {
      int numb = (int) __builtin_popcount(mask); 
      for (int i = 0; i < (int) listBit1[mask].size(); i++) {
        int u = listBit1[mask][i];
        if (adj[numb - 1][u] == false) {
          continue; 
        }
        long long ways = f_prefix[mask ^ (1 << u)] * f_suffix[((1 << n) - 1) ^ mask]; 
        ans[numb - 1][u] += 1.0 * ways; 
      }
    }
    std::cout << std::fixed << std::setprecision(8); 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        std::cout << ans[i][j] / omega << ' ';
      }
      std::cout << std::endl; 
    }
  }
  return 0; 
}