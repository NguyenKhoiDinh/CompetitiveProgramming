#include <iostream>
#include <vector>
int numTest; 
int n;        
std::vector <long long> a; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    a.clear();
    a.resize(n); 
    for (int i = 0; i < n; i++) {
      std::cin >> a[i]; 
    }
    int ans = 0; 
    while (a.empty() == false) {
      if ((int) a.size() > 1 && a.back() > a[(int) a.size() - 2]) {
        long long total = a.back() + a[(int) a.size() - 2]; 
        a.pop_back(); 
        a.pop_back(); 
        a.push_back(total); 
      }
      else {
        ans++;
        a.pop_back(); 
      }
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}