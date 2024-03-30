#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
std::vector <int> X1, Y1, Z1, X2, Y2, Z2; 
int n, k; 
std::vector <std::pair <int, int> > segX, segY, segZ; 
std::vector <long long> maskX, maskY, maskZ; 
void process(const std::vector <int> &L, const std::vector <int> &R, std::vector <std::pair <int, int> > &a, std::vector <long long> &mask) {
  std::cout << "--------------------" << std::endl; 
  std::vector <int> tmp; 
  for (int i = 0; i < n; i++) {
    tmp.push_back(L[i] - 1);
    tmp.push_back(R[i]); 
  }
  std::sort(tmp.begin(), tmp.end()); 
  for (int i = 1; i < (int) tmp.size(); i++) {
    if (tmp[i] != tmp[i - 1]) {
      a.push_back(std::make_pair(tmp[i - 1] + 1, tmp[i])); 
    }
  }
  int sz = (int) a.size(); 
  mask.resize(sz, 0LL); 
  for (int i = 0; i < sz; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i].first > R[j] || L[j] > a[i].second) {
        continue; 
      }
      mask[i] |= (1LL << j); 
    }
  }
  for (int i = 0; i < (int) a.size(); i++) {
    std::cout << a[i].first << "    " << a[i].second ;
    std::cout << ":    "; 
    for (int j = 0; j < n; j++) {
      if ((mask[i] & (1LL << j)) > 0) {
        std::cout << j << "  "; 
      }
    }
    std::cout << std::endl; 
  }
  std::cout << std::endl;                       
  
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout); 
  std::cin >> n >> k;
  X1.resize(n);
  Y1.resize(n);
  Z1.resize(n);
  X2.resize(n);
  Y2.resize(n);
  Z2.resize(n); 
  for (int i = 0; i < n; i++) {
    std::cin >> X1[i] >> Y1[i] >> Z1[i] >> X2[i] >> Y2[i] >> Z2[i]; 
  }
  process(X1, X2, segX, maskX);
  process(Y1, Y2, segY, maskY);
  process(Z1, Z2, segZ, maskZ);
  long long ans = 0LL; 
  for (int x = 0; x < (int) segX.size(); x++) {
    for (int y = 0; y < (int) segY.size(); y++) {
      for (int z = 0; z < (int) segZ.size(); z++) {
        int mask = maskX[x] & maskY[y] & maskZ[z];
        int cnt = (int) __builtin_popcount(mask);
        if (cnt >= k) {
          ans += 1LL * (segX[x].second - segX[x].first) * (segY[y].second - segY[y].first) * (segZ[z].second - segZ[z].first); 
        }   
      }
    }
  }
  std::cout << ans; 
  return 0; 
}