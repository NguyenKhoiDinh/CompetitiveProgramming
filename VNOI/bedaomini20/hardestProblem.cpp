#include <iostream>
#include <vector>
#include <math.h>
struct query {
  int l, r, x; 
};
std::vector <query> listQueries; 
int n, numQueries; 

int main () {
  std::cin >> n >> numQueries; 
  for (int q = 1; q <= numQueries; q++) {
    int type;
    std::cin >> type;
    if (type == 1) {
      int l, r, x;
      std::cin >> l >> r >> x;
      listQueries.push_back((query) {l, r, x});   
    }
    else {
      int ans = 0;
      int lo, hi;
      std::cin >> lo >> hi;  
      for (int i = 0; i < (int) listQueries.size(); i++) {
        int l = listQueries[i].l; 
        int r = listQueries[i].r;
        int x = listQueries[i].x; 
        int tmplo = std::max(lo, l);
        int tmphi = std::min(hi, r);
        if (tmplo <= tmphi && ((tmphi - tmplo + 1) % 2) == 1) {
          ans ^= x;   
        } 
      }
      listQueries.clear();
      std::cout << ans << std::endl;
    }
  }
  return 0; 
}