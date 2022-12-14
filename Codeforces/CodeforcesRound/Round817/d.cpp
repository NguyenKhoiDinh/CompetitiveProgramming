#include <iostream>
#include <math.h>
#include <string>  
int numTest; 
int n; 
std::string s; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    std::cin >> s;
    long long ans = 0LL; 
    for (int i = 0; i < n; i++) {
      if (s[i] == 'L') {
        ans += (long long) i; 
      }
      else {
        ans += (long long) (n - i - 1); 
      }
    }
    int left = 0, right = n - 1;
    for (int k = 1; k <= n; k++) {
      while (left <= right) {
        int addLeft = n - 1 - left; 
        int addRight = right; 
        if (addLeft > addRight) {
          if (s[left] == 'L') {
            ans = ans - left + (n - 1 - left);
            left++;
            break; 
          }
          left++; 
        }
        else if (addLeft < addRight) {
          if (s[right] == 'R') {
            ans = ans - (n - 1 - right) + right; 
            right--; 
            break; 
          }
          right--; 
        }
        else {
          if (s[left] == 'L') {
            ans = ans - left + (n - 1 - left);
            left++;
            break;
          }
          left++; 
        }
      }
      std::cout << ans << ' ';   
    }    
    std::cout << std::endl; 
  }
  return 0; 
}