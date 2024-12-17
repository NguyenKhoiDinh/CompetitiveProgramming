#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <utility>  
struct block {
  int w, h; 
  bool operator < (const block &other) {
    return h < other.h; 
  }
};
block a[300005]; 
int n; 

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  freopen("rainfall.inp", "r", stdin);
  freopen("rainfaill.out", "w", stdout);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].w >> a[i].h; 
    if (a[i].h < a[i].w) {
      std::swap(a[i].h, a[i].w); 
    }
  } 
  std::sort(a + 1, a + n + 1); 
  long long sumH = 0LL;
  long long sumS = 0LL; 
  int minH = 1000005;  
  bool deleted = false; 
  std::priority_queue <std::pair <int, int> > pq;
  long long ans = 0LL;  
  for (int i = n; i >= 1; i--) {
    if (i < n) {
      while (pq.empty() == false && pq.top().first >= a[i].h) {
        deleted = true;
        sumH -= pq.top().second;
        pq.pop();  
      }
    }   
  }
  return 0; 
}