#include <iostream>
#include <math.h> 
#include <vector>
#include <algorithm> 
#include <utility> 
#include <deque> 
int n, C;
std::pair <int, int> a[200005]; 
std::deque <int> mydeque; 

int main () {
  std::cin >> n >> C; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first; 
  }         
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].second;
  }
  std::sort(a + 1, a + n + 1);
  int ans = 1000000007;
  int sum = 0;
  int l = 1; 
  for (int i = 1; i <= n; i++) {
    sum += a[i].second;
    if (l <= i - 1) {
      while (mydeque.empty() == false && a[mydeque.back() + 1].first - a[mydeque.back()].first <= a[i].first - a[i - 1].first) {
        mydeque.pop_back(); 
      }
      mydeque.push_back(i - 1);       
    }
    while (sum >= C) {
      if (mydeque.empty() == true) {
        ans = std::min(ans, 0); 
      }
      else {             
        ans = std::min(ans, a[mydeque.front() + 1].first - a[mydeque.front()].first);
      }
      if (l == mydeque.front()) {
        mydeque.pop_front(); 
      }
      sum -= a[l].second;
      l++; 
    } 
  } 
  std::cout << ans; 
  return 0; 
}