#include <iostream>
#include <algorithm>
#include <queue>  
#include <vector>
#include <utility> 
int numTest;
int n, m, L;
std::vector <std::pair <int, int> > hurdles;
std::vector <std::pair <int, int> > powerUp;   

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m >> L;
    hurdles.clear();
    powerUp.clear();
    for (int i = 1; i <= n; i++) {
      int l, r;
      std::cin >> l >> r;
      hurdles.push_back(std::make_pair(l, r)); 
    }     
    for (int i = 1; i <= m; i++) {
      int position, value;
      std::cin >> position >> value; 
      powerUp.push_back(std::make_pair(position, value)); 
    }
    std::priority_queue <int> pq;
    int p = 0;
    long long currentPower = 1LL;
    bool canSolved = true;
    int ans = 0;   
    for (int i = 0; i < n; i++) {
      while (p < m && powerUp[p].first < hurdles[i].first) {
        pq.push(powerUp[p].second);
        p++;    
      }
      while (currentPower < hurdles[i].second + 2 - hurdles[i].first && pq.empty() == false) {
        currentPower += pq.top();
        ans++; 
        pq.pop(); 
      }
      if (currentPower < hurdles[i].second + 2 - hurdles[i].first) {
        canSolved = false;
        break;  
      }
    }
    std::cout << (canSolved == true ? ans : -1) << std::endl;
  }
  return 0; 
}