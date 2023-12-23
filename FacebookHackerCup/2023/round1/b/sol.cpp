#include <iostream>
#include <math.h> 
#include <vector> 
int numTest; 

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::vector <int> ans; 
    int P;
    std::cin >> P;
    for (int i = 2; i <= 40000; i++) {
      while (P % i == 0) {
        ans.push_back(i);
        P /= i;   
      }
    }
    if (P > 1) {
      ans.push_back(P); 
    }
    int sum = 0; 
    for (int i = 0; i < (int) ans.size(); i++) {
      sum += ans[i]; 
    }
    if (sum > 41) {
      std::cout << -1 << std::endl;
    }
    else {
      while (sum < 41) {
        ans.push_back(1); 
        sum++; 
      }
      std::cout << (int) ans.size() << ' ';
      for (int i = 0; i < (int) ans.size(); i++) {
        std::cout << ans[i] << ' '; 
      } 
      std::cout << std::endl;
    }
    std::cerr << "Case #" << testCase << ": DONE" << std::endl;
  } 
  return 0; 
}