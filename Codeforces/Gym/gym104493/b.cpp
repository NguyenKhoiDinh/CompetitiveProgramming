#include <iostream>
#include <vector> 
#include <math.h> 
#include <algorithm>
#include <utility>
int n, numQueries; 
int a[2000005]; 
bool isPrime[2000005];
int maxPrime[2000005];  
void erathones() {
  for (int i = 2; i <= 2000000; i++) {
    isPrime[i] = true; 
  }  
  for (int i = 2; i <= 2000000; i++) {
    if (isPrime[i] == true) {
      maxPrime[i] = i; 
      for (int j = 2 * i; j <= 2000000; j += i) {
        isPrime[j] = false;
        maxPrime[j] = std::max(maxPrime[j], i);  
      }
    }
  }
}
int t[2000005];
int rmq[2000005][21];
std::vector <int> index[2000005];  

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL); 
  erathones(); 
  std::cin >> n >> numQueries; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
    index[a[i]].push_back(i); 
  }
  int step = 0; 
  std::vector <std::pair <int, int> > v1; 
  for (int v = 2000000; v >= 2; v--) {
    std::vector <int> &pos = index[v];
    for (int j = 0; j < (int) pos.size(); j++) {
      int u = v / maxPrime[v];
      if (u == 1) {
        v1.push_back(std::make_pair(step, pos[j]));
      }
      else {
        index[u].push_back(pos[j]); 
      }                                
    } 
    step += (int) pos.size();
    pos.clear();    
  }
  std::sort(v1.begin(), v1.end());
  int tt = 0;
  for (int i = 0; i < (int) v1.size(); i++) {
    if (i > 0 && v1[i].first > v1[i - 1].first) {
      tt = 1; 
    } 
    else {
      tt++; 
    }
    t[v1[i].second] = v1[i].first + tt;
  } 
  for (int i = 1; i <= n; i++) {
    rmq[i][0] = t[i]; 
  }
  for (int j = 1; j <= 20; j++) {
    for (int i = 1; i <= n; i++) {
      if ((i + (1 << j) - 1) <= n) {
        rmq[i][j] = std::max(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]); 
      }
    }
  }
  for (int query = 1; query <= numQueries; query++) {
    int l, r;
    std::cin >> l >> r;
    int lg = (int) std::log2(r - l + 1);
    std::cout << std::max(rmq[l][lg], rmq[r - (1 << lg) + 1][lg]) << std::endl;                             
  }
  return 0; 
}