#include <iostream>
#include <math.h> 
int numTest; 
int n, m, d; 
int s[100005]; 
int prefix[100005], suffix[100005]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m >> d;
    for (int i = 1; i <= m; i++) {
      std::cin >> s[i]; 
    }    
    prefix[0] = 0; 
    prefix[1] = 1 + (s[1] == 1 ? 0 : 1) + (s[1] - 2) / d; 
    for (int i = 2; i <= m; i++) {
      prefix[i] = prefix[i - 1] + 1 + (s[i] - 1 - s[i - 1]) / d; 
    }
    suffix[m + 1] = 0; 
    suffix[m] = 1 + (n - s[m]) / d; 
    for (int i = m - 1; i >= 1; i--) {
      suffix[i] = suffix[i + 1] + 1 + (s[i + 1] - 1 - s[i]) / d; 
    }
    int ans = 1 + (s[2] - 2) / d + suffix[2];
    int numb = 1;     
    if (ans > prefix[m - 1] + (n - s[m - 1]) / d) {
      ans = prefix[m - 1] + (n - s[m - 1]) / d;
      numb = 1; 
    }
    else if (ans == prefix[m - 1] + (n - s[m - 1]) / d) {
      numb++; 
    }
    for (int i = 2; i < m; i++) {                                                                             
      if (ans > prefix[i - 1] + suffix[i + 1] + (s[i + 1] - 1 - s[i - 1]) / d) {
        ans = prefix[i - 1] + suffix[i + 1] + (s[i + 1] - 1 - s[i - 1]) / d;
        numb = 1;  
      }
      else if (ans == prefix[i - 1] + suffix[i + 1] + (s[i + 1] - 1 - s[i - 1]) / d) {
        numb++; 
      }
    }
    std::cout << ans << ' ' << numb << std::endl; 
  }
  return 0; 
}