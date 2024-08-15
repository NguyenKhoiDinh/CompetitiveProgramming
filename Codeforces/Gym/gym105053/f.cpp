#include <iostream> 
#include <algorithm>
#include <vector>  
#include <math.h> 
#include <bitset> 
int g[200005], r[200005], cnt[200005]; 
int n;
int f[2][200005];  
std::vector <int> item; 

int main () {
  std::ios_base::sync_with_stdio(false); 
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::cin >> n;
  int gcd = -1; 
  int sum = 0; 
  bool isG0 = false; 
  for (int i = 1; i <= n; i++) {
    std::cin >> g[i] >> r[i]; 
    if (g[i] == 0) {
      isG0 = true; 
    }
    sum += g[i];
    cnt[g[i]]++;  
    if (gcd == -1) {
      gcd = r[i]; 
    }
    else {
      gcd = std::__gcd(gcd, r[i]); 
    }
  }
  if (isG0 == true && sum % gcd == 0) {
    std::cout << "Y";
    return 0;
  }
  for (int i = 1; i <= 200000; i++) {
    int v = 1;
    while (cnt[i] >= v) {
      item.push_back(v * i);
      cnt[i] -= v;
      v *= 2;    
    }
    if (cnt[i] > 0) {
      item.push_back(cnt[i] * i); 
    }    
  }
  f[0][0] = 1; 
  int sz = (int) item.size(); 
  for (int i = 0; i < sz; i++) {
    int cur = i % 2; 
    int nxt = !cur; 
    for (int j = 0; j <= 200000; j++) {
      if (f[cur][j] == 0) {
        continue; 
      }
      f[nxt][j + item[i]] = 1;
      f[nxt][j] = 1;  
    }
  }
  bool ans = false; 
  for (int sumg = 1; sumg < sum; sumg++) {
    if (f[n % 2][sumg] == 0) {
      continue;   
    }
    int suma = sumg;
    int sumb = sum - suma; 
    int value = suma - sumb;
    if (std::abs(value) % gcd == 0) {
      std::cout << "Y";
      return 0; 
    }
  }
  std::cout << "N";
  return 0; 
}