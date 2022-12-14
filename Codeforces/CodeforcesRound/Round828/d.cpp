#include <iostream> 
#include <algorithm> 
#include <vector> 
int numTest; 
int a[200005]; 
int n; 
std::vector <int> listPower; 

int calc(int x) {
  int ret = 0; 
  while (x % 2 == 0) {
    ret++;
    x /= 2; 
  }
  return ret; 
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    listPower.clear();
    int totalPower = 0; 
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
      totalPower += calc(a[i]);
      listPower.push_back(calc(i));  
    }   
    std::sort(listPower.begin(), listPower.end());
    int ans = 0; 
    while (totalPower < n && listPower.empty() == false) {
      totalPower += listPower.back(); 
      ans++; 
      listPower.pop_back(); 
    } 
    if (totalPower < n) {
      std::cout << -1; 
    }
    else {
      std::cout << ans; 
    }
    std::cout << std::endl; 
  }
  return 0; 
}