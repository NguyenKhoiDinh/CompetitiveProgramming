#include <iostream> 
#include <iomanip> 
#include <math.h> 
bool check[1000005]; 
int n, numTest;
double a[1000005];
double ans = -1.0;
void backTrack(int pos, double sum) {
  if (pos == n) {
    ans = std::max(ans, sum); 
    return; 
  }
  for (int i = 1; i <= n; i++) {
    if (check[i] == false) {
      check[i] = true; 
      int numb = 0; 
      if (i > 1 && check[i - 1] == false) {
        numb++; 
      }
      if (i < n && check[i + 1] == false) {
        numb++; 
      }
      if (numb == 2) {
        backTrack(pos + 1, sum + 0.5 * (a[i - 1] + a[i + 1]));    
      }
      else if (numb == 1) {
        if (i > 1 && check[i - 1] == false) {
          backTrack(pos + 1, sum + a[i - 1]); 
        }
        else {
          backTrack(pos + 1, sum + a[i + 1]); 
        }
      }
      else {
        backTrack(pos + 1, sum);
      }
      check[i] = false;
    }
  }
} 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
      check[i] = false; 
    }
    ans = -1.0; 
    if (n <= 8) {
      backTrack(1, 0.0); 
      std::cout << std::fixed << std::setprecision(1) << ans << std::endl; 
      continue; 
    }
    ans = 0.0; 
    for (int i = 2; i < n; i++) {
      ans += a[i]; 
    }
    ans *= 2.0; 
    std::cout << std::fixed << std::setprecision(1) << ans << std::endl;
  }
  return 0; 
}