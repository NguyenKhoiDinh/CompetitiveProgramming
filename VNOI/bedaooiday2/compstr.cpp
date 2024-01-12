#include <iostream>
#include <math.h>
#include <string> 
#include <vector>
std::string s; 
int f[5005]; 
int cost[5005][5005]; 
std::vector <int> listDivisor[5005]; 

int calc(int length) {
  if (length < 10) {
    return 1; 
  }
  if (length < 100) {
    return 2; 
  }
  if (length < 1000) {
    return 3; 
  }
  return 4;
}

int main () {
  freopen("compstr.inp", "r", stdin);
  freopen("compstr.out", "w", stdout);
  std::cin >> s; 
  int n = (int) s.size(); 
  s = "." + s;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      if (i % j == 0) {
        listDivisor[i].push_back(j); 
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      cost[i][j] = 1000005; 
      std::string st = "";
      for (int k = i; k <= j; k++) {
        st += s[k]; 
      }
      for (int k = 0; k < (int) listDivisor[j - i + 1].size(); k++) {
        int d = listDivisor[j - i + 1][k]; 
        bool check = true; 
        for (int x = 0; x < (int) st.size(); x++) {
          if (st[x] != st[x % d]) {
            check = false;
            break;
          }
        }
        if (check == true) {
          cost[i][j] = std::min(cost[i][j], calc((j - i + 1) / d) + d); 
        }
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    f[i] = 1000005; 
  }
  f[0] = 0;
  for (int i = 0; i < n; i++) {
    if (f[i] == 1000005) {
      continue; 
    }
    for (int j = i + 1; j <= n; j++) {
      f[j] = std::min(f[j], f[i] + cost[i + 1][j]); 
    }
  }
  std::cout << f[n]; 
  return 0; 
}