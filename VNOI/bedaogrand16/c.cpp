#include <iostream>
#include <string> 
#include <utility>
#include <algorithm> 
int n, m, numQueries;                  
struct frog {
  long long sumx = 0;
  bool signx = true; 
  long long sumy = 0;
  bool signy = true;
  bool isSwap = false;  
};
frog pat; 
std::pair <int, int> a[200005]; 
frog cw(frog a) {
  frog ret = a;
  std::swap(ret.sumx, ret.sumy);
  std::swap(ret.signx, ret.signy);
  ret.signy = !ret.signy;
  ret.sumy = -ret.sumy; 
  ret.isSwap = !ret.isSwap; 
  return ret;   
}
frog ccw(frog a) {
  frog ret = a; 
  ret = cw(ret);
  ret = cw(ret);
  ret = cw(ret);
  return ret;  
}
frog event[200005]; 

int main () {
  std::cin >> n >> m >> numQueries; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first >> a[i].second; 
  }
  for (int i = 1; i <= m; i++) {
    std::string type; 
    std::cin >> type; 
    if (type == "cw") {
      pat = cw(pat);   
    }
    else if (type == "ccw") {
      pat = ccw(pat); 
    }
    else if (type == "xflip") {
      long long k;
      std::cin >> k;
      pat.sumx = 2LL * k - pat.sumx;
      pat.signx = !pat.signx;   
    }
    else {
      long long k;
      std::cin >> k; 
      pat.sumy = 2LL * k - pat.sumy; 
      pat.signy = !pat.signy; 
    }
    event[i] = pat; 
  }
  for (int query = 1; query <= numQueries; query++) {
    int id, e;
    std::cin >> id >> e;
    long long x = event[e].sumx;
    x += (long long) (event[e].signx == true ? 1 : -1) * (event[e].isSwap == false ? a[id].first : a[id].second);
    long long y = event[e].sumy;
    y += (long long) (event[e].signy == true ? 1 : -1) * (event[e].isSwap == false ? a[id].second : a[id].first);
    std::cout << x << ' ' << y << std::endl;    
  }
  return 0; 
}