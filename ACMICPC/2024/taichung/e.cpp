#include <iostream> 
#include <vector> 
int mean, median; 

int main () {
  std::cin >> mean >> median; 
  for (int n = 1; n <= 1000; n++) {
    int sum = n * mean; 
    std::vector <int> ans(n);
    if (n % 2 == 1) {
      if (n == 1) {
        if (mean == median) {
          std::cout << 1 << std::endl;
          std::cout << mean;
          return 0; 
        }
        continue; 
      }
      ans[n / 2] = median;
      sum -= median; 
      for (int i = 0; i < n / 2; i++) {
        ans[i] = -1000;
        sum += 1000;  
      }
      for (int i = n / 2 + 1; i < n - 1; i++) {
        ans[i] = median;
        sum -= median;  
      }  
      if (sum >= median) {
        ans[n - 1] = sum; 
        std::cout << n << std::endl;
        for (int i = 0; i < n; i++) {
          std::cout << ans[i] << ' ';
        }
        return 0;
      }      
    }
    else {
      if (n == 2) {
        if (mean == median) {
          std::cout << 2 << std::endl; 
          std::cout << mean << ' ' << mean;
          return 0;
        }
        continue;
      }
      ans[n / 2 - 1] = median;
      ans[n / 2] = median;
      sum -= 2 * median;
      for (int i = 0; i < n / 2 - 1; i++) {
        ans[i] = -1000;
        sum += 1000;   
      }      
      for (int i = n / 2 + 1; i < n - 1; i++) {
        ans[i] = median; 
        sum -= median; 
      }
      if (sum >= median) {
        ans[n - 1] = sum; 
        std::cout << n << std::endl;
        for (int i = 0; i < n; i++) {
          std::cout << ans[i] << ' '; 
        }
        return 0; 
      }
    }
  }
  return 0; 
}