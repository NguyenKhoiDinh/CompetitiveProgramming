#include <iostream>
#include <vector>
#include <algorithm> 
#include <map>
int numTest;
int n, k; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k;
    std::map <int, std::vector <int> > id; 
    for (int i = 1; i <= n; i++) {
      int x;
      std::cin >> x;          
      id[x % k].push_back(i); 
    }
    std::vector <int> ans; 
    for (int i = 0; i < (int) id[0].size(); i++) {
      ans.push_back(id[0][i]); 
    }
    std::vector <int> tmp; 
    for (std::map <int, std::vector <int> >::iterator it = id.begin(); it != id.end(); it++) {
      if (it->first > 0) {
        std::vector <int> &v = it->second; 
        for (int i = (int) v.size() - 1; i >= 0; i--) {
          tmp.push_back(v[i]); 
        }
      }
    }
    std::reverse(tmp.begin(), tmp.end());
    for (int i = 0; i < (int) ans.size(); i++) {
      std::cout << ans[i] << ' '; 
    } 
    for (int i = 0; i < (int) tmp.size(); i++) {
      std::cout << tmp[i] << ' '; 
    }
    std::cout << std::endl;
  }
  return 0; 
}