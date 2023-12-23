#include <iostream>
#include <string>
#include <math.h>
int cntR[400005], cntS[400005], cntP[400005]; 
std::string s; 
int n, numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> s;
    n = (int) s.size(); 
    for (int i = 0; i <= n; i++) {
      cntR[i] = 0;
      cntS[i] = 0;
      cntP[i] = 0; 
    }
    for (int i = 1; i <= n; i++) {
      cntR[i] = cntR[i - 1];
      cntS[i] = cntS[i - 1];
      cntP[i] = cntP[i - 1]; 
      if (s[i - 1] == 'R') {
        cntR[i]++;
      }
      else if (s[i - 1] == 'S') {
        cntS[i]++;
      }
      else {
        cntP[i]++;
      }
    }
    for (int i = n + 1; i <= 2 * n; i++) {
      cntR[i] = cntR[i - 1];
      cntS[i] = cntS[i - 1];
      cntP[i] = cntP[i - 1]; 
    }
    int maxWin = -1; 
    int ans = -1;
    for (int k = n; k >= 2; k--) {
      int numbWin = 0; 
      for (int i = k; i <= n + k; i += k) {
        int numbR = cntR[i] - cntR[i - k];
        int numbS = cntS[i] - cntS[i - k];
        int numbP = cntP[i] - cntP[i - k];
        numbWin += std::max(numbR, std::max(numbS, numbP)); 
      }
      if (maxWin < numbWin) {
        maxWin = numbWin; 
        ans = k; 
      }
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}