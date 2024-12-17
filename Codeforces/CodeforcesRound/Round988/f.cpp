#include <iostream>
#include <vector>
#include <map>  
#include <algorithm> 
#include <utility> 
int numTest;
int n, m, k;

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m >> k;
    std::vector <long long> health(n), position(n); 
    for (int i = 0; i < n; i++) {
      std::cin >> health[i]; 
    } 
    for (int i = 0; i < n; i++) {
      std::cin >> position[i]; 
    }
    long long ans = -1; 
    long long lo = 1;
    long long hi = 1000000007LL; 
    while (lo <= hi) {
      long long mid = (lo + hi) / 2;
      std::vector <std::pair <int, int> > listSegments;
      for (int i = 0; i < n; i++) {
        if (position[i] <= m + position[i] - (health[i] + mid - 1) / mid) {
          listSegments.push_back(std::make_pair(position[i], m + position[i] - (health[i] + mid - 1) / mid)); 
        }   
        if ((health[i] + mid - 1) / mid - m + position[i] < position[i]) {
          listSegments.push_back(std::make_pair((health[i] + mid - 1) / mid - m + position[i], position[i] - 1)); 
        }
      }                                                            
      std::map <int, int> f;
      int sz = (int) listSegments.size();
      for (int i = 0; i < sz; i++) {
        std::pair <int, int> &current = listSegments[i];
        f[current.first]++;
        f[current.second + 1]--;     
      }
      bool solved = false; 
      int total = 0; 
      for (std::map <int, int>::iterator it = f.begin(); it != f.end(); it++) {
        total += it->second;
        if (total >= k) {
          solved = true;
          break;   
        }  
      }                                                                                   
      if (solved == true) {
        ans = mid;                    
        hi = mid - 1; 
      }
      else {
        lo = mid + 1; 
      }
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}