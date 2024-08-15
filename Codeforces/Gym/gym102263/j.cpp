#include <iostream>
#include <string> 
#include <algorithm> 
#include <math.h> 
std::string N;
int f[100005][2];  
int n; 
const int inf = 1000000007; 

int main () {
  std::cin >> N; 
  std::reverse(N.begin(), N.end()); 
  n = (int) N.size(); 
  for (int i = 0; i <= n; i++) {
    f[i][0] = inf;
    f[i][1] = inf; 
  }
  f[1][0] = N[0] - '0'; 
  f[1][1] = 1 + 10 - (N[0] - '0');
  for (int i = 1; i < n; i++) {
    for (int rem = 0; rem <= 1; rem++) {
      if (f[i][rem] == inf) {
        continue; 
      }
      int x = N[i] - '0'; 
      if (rem == 0) {
        f[i + 1][0] = std::min(f[i + 1][0], f[i][rem] + x);
        f[i + 1][1] = std::min(f[i + 1][1], f[i][rem] + 1 + 10 - x);        
      }
      else {
        f[i + 1][0] = std::min(f[i + 1][0], f[i][rem] + x); 
        f[i + 1][1] = std::min(f[i + 1][1], f[i][rem] + 9 - x); 
      }
    }
  } 
  std::cout << std::min(f[n][0], f[n][1]); 
  return 0; 
}