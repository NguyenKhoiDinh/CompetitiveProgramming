#include <iostream>
#include <string> 
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    std::cin >> n;
    int total;  
    std::cout << "? " << 1 << ' ' << n << std::endl;
    fflush(stdout);
    std::cin >> total;
    if (n == 2) {
      if (total == 0) {
        std::cout << "! IMPOSSIBLE" << std::endl; 
      }
      else {
        std::cout << "! 01" << std::endl; 
      }
      fflush(stdout); 
      continue; 
    }
    std::string ans;
    if (total == 0) {
      std::cout << "! IMPOSSIBLE" << std::endl;
      fflush(stdout);
      continue; 
    }
    int previous = total; 
    ans.resize(n, '0'); 
    int current; 
    int position = 1;
    for (int i = n - 1; i >= 2; i--) {
      std::cout << "? " << 1 << ' ' << i << std::endl;
      fflush(stdout); 
      std::cin >> current;
      if (current == 0) {
        ans[i] = '1';
        position = i; 
        break; 
      } 
      else {
        if (current < previous) {
          ans[i] = '1'; 
        }  
        else {
          ans[i] = '0'; 
        }
      }
      previous = current;
    }
    if (position == 1) {
      ans[0] = '0';
      ans[1] = '1';  
      std::cout << "! " << ans << std::endl;
      fflush(stdout);
      continue; 
    }
    int numbOnes = 0; 
    for (int i = n; i > position; i--) {
      if (ans[i - 1] == '1') {
        numbOnes++;   
      }
      else {
        total -= numbOnes;   
      }
    }
    for (int i = position; i >= 1; i--) {
      if (total > 0) {
        ans[i - 1] = '0'; 
        total -= numbOnes; 
      }
      else {
        for (int j = i; j >= 1; j--) {
          ans[j - 1] = '1'; 
        }
        break; 
      }
    } 
    std::cout << "! " << ans << std::endl;
    fflush(stdout);
  }
  return 0; 
}