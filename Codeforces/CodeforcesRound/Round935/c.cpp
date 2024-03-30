#include <iostream>
#include <math.h> 
#include <string>
int numTest;     
std::string s; 
int pref[300005], suf[300005]; 
int n; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    std::cin >> s; 
    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + (s[i - 1] == '0'); 
    }
    suf[n + 1] = 0;
    for (int i = n; i >= 1; i--) {
      suf[i] = suf[i + 1] + (s[i - 1] == '1'); 
    }
    double half = 1.0 * n / 2.0; 
    double minDist = (double) (n + 10.0); 
    int ans = 0; 
    for (int i = 0; i <= n; i++) {
      int numbZeros = (i + 1) / 2; 
      int numbOnes = (n - i + 1) / 2; 
      if (pref[i] >= numbZeros && suf[i + 1] >= numbOnes) {
        if (minDist > std::abs((double) i - half)) {
          ans = i;
          minDist = std::abs((double) i - half); 
        }
      }
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}