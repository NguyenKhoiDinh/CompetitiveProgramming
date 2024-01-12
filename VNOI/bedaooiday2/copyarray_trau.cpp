#include <iostream>
#include <math.h>
#include <vector>  
int n, numQueries;
std::vector <int> a[1005];  

int main () {
  freopen("copyarray.inp", "r", stdin);
  freopen("copyarray2.inp", "w", stdout);
  std::cin >> n >> numQueries; 
  a[0].resize(n); 
  for (int i = 0; i < n; i++) {
    std::cin >> a[0][i]; 
  }
  for (int query = 1; query <= numQueries; query++) {
    int type, id, value;
    std::cin >> type >> id >> value; 
    if (type == 1) {
      a[query] = a[id];
      a[query].push_back(value);   
    }
    else {
      a[query] = a[id]; 
      for (int i = 0; i < (int) a[query].size(); i++) {
        a[query][i] ^= value; 
      }
    }
  }
  for (int i = 0; i <= numQueries; i++) {
    int minValue = a[i][0]; 
    for (int j = 1; j < (int) a[i].size(); j++) {
      minValue = std::min(minValue, a[i][j]); 
    }
    std::cout << minValue << ' '; 
  }
  return 0; 
}