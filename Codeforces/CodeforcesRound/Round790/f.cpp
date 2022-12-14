#include <iostream> 
#include <map> 
#include <vector> 
int numTest; 
int n, k; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::map <int, int> cnt; 
    std::cin >> n >> k; 
    for (int i = 1; i <= n; i++) {
      int x; 
      std::cin >> x; 
      cnt[x]++; 
    }
    std::vector <int> save; 
    save.push_back(-1); 
    for (std::map <int, int> :: iterator it = cnt.begin(); it != cnt.end(); it++) {
      if (it->second >= k) {
        save.push_back(it->first); 
      }
    }
    if ((int) save.size() == 1) {
      std::cout << -1 << std::endl; 
      continue; 
    }
    int ans = 0; 
    int cont = 0;
    int pos = -1; 
    for (int i = 1; i < (int) save.size(); i++) {
      if (save[i] > save[i - 1] + 1) {
        cont = 1; 
      }
      else {
        cont++; 
      }
      if (ans < cont) {
        ans = cont; 
        pos = i; 
      } 
    }
    std::cout << save[pos] - ans + 1 << ' ' << save[pos] << std::endl; 
  }
  return 0; 
}