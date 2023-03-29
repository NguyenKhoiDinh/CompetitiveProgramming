#include <iostream>
#include <algorithm>
#include <utility> 
#include <vector> 
#include <math.h>
int n, S; 
std::vector <std::pair <int, int> > chosen, notChosen; 
long long ans = 0LL; 
long long totalCost = 0LL; 
int totalWeight = 0LL; 
int maxValue[100005]; 

int main () {
  std::cin >> n >> S; 
  for (int i = 1; i <= n; i++) {
    int w, v, c;
    std::cin >> w >> v >> c; 
    if (c == 1) {
      chosen.push_back(std::make_pair(w, v)); 
      totalCost += v; 
      totalWeight += w; 
    }
    else {
      notChosen.push_back(std::make_pair(w, v)); 
    }
  }
  ans = totalCost; 
  std::sort(notChosen.begin(), notChosen.end()); 
  int n1 = (int) chosen.size(); 
  int n2 = (int) notChosen.size(); 
  if (n2 == 0) {
    std::cout << ans; 
    return 0; 
  }
  maxValue[0] = notChosen[0].second; 
  for (int i = 1; i < n2; i++) {
    maxValue[i] = std::max(maxValue[i - 1], notChosen[i].second); 
  }
  for (int i = 0; i < n1; i++) {
    int remainWeight = S - (totalWeight - chosen[i].first); 
    int lo = 0;
    int hi = n2 - 1; 
    int position = -1; 
    while (lo <= hi) {
      int mid = (lo + hi) / 2; 
      if (notChosen[mid].first <= remainWeight) {
        position = mid; 
        lo = mid + 1; 
      }
      else {
        hi = mid - 1; 
      }
    }
    if (position != -1) {
      ans = std::max(ans, totalCost - chosen[i].second + maxValue[position]); 
    }
  }
  std::cout << ans; 
  return 0; 
}