#include <iostream>
#include <algorithm> 
#include <math.h> 
#include <iomanip> 
int numTest; 
double f[100005][2]; 
double X[100005]; 
int n; 
double midPoint[100005][2]; 

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> X[i];
    }
    std::sort(X + 1, X + n + 1); 
    for (int i = 2; i <= n; i++) {
      midPoint[i][0] = (X[i] + X[i - 1]) / 2.0; 
      if (i >= 3) {
        midPoint[i][1] = (X[i] + X[i - 2]) / 2.0; 
      }
    }
    for (int i = 0; i <= n; i++) {
      f[i][0] = f[i][1] = -1.0000000; 
    }
    f[2][0] = 0.0000; 
    f[3][1] = 0.0000; 
    for (int i = 2; i <= n - 2; i++) {
      if (f[i][0] != -1.0000000) {
        if (i + 2 <= n) {
          f[i + 2][0] = std::max(f[i + 2][0], f[i][0] + midPoint[i + 2][0] - midPoint[i][0]);   
        }  
        if (i + 3 <= n) {
          f[i + 3][1] = std::max(f[i + 3][1], f[i][0] + midPoint[i + 3][1] - midPoint[i][0]); 
        }
      }
      if (f[i][1] != -1.0000000) {
        if (i + 2 <= n) {
          f[i + 2][0] = std::max(f[i + 2][0], f[i][1] + midPoint[i + 2][0] - midPoint[i][1]);   
        }  
        if (i + 3 <= n) {
          f[i + 3][1] = std::max(f[i + 3][1], f[i][1] + midPoint[i + 3][1] - midPoint[i][1]); 
        }
      }
    }
    std::cout << std::fixed << std::setprecision(12) << std::max(f[n][0], f[n][1]) << std::endl;
    std::cerr << "Case #" << testCase << ": DONE" << std::endl;
  } 
  return 0; 
}