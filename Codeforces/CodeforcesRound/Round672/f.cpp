#include <iostream>
#include <math.h>
#include <vector>
const int inf = 82 * 82 * 82 + 7; 
int f[2][82][82 * 82]; 
int a[82]; 
std::vector <int> listGroup; 
int n; 
int prefixSum[82]; 

void updateMin(int &a, int b) {
  a = std::min(a, b); 
}

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  a[0] = 1;
  a[n + 1] = 1; 
  int lastPosition = 0; 
  for (int i = 1; i <= n + 1; i++) {
    if (a[i] == 1) {
      listGroup.push_back(i - 1 - lastPosition);
      lastPosition = i; 
    }
  }
  int sz = (int) listGroup.size(); 
  for (int i = 1; i <= sz; i++) {
    prefixSum[i] = prefixSum[i - 1] + listGroup[i - 1]; 
  }
  int totalZeros = prefixSum[sz]; 
  for (int i = 0; i <= 1; i++) {
    for (int sum = 0; sum <= totalZeros; sum++) {
      for (int totalStep = 0; totalStep <= n * (n - 1) / 2; totalStep++) {
        f[i][sum][totalStep] = inf; 
      }
    }
  }
  f[0][0][0] = 0; 
  for (int i = 0; i < sz; i++) {
    int cur = i & 1;                             
    int nxt = !cur; 
    for (int sum = 0; sum <= totalZeros; sum++) {
      for (int totalStep = 0; totalStep <= n * (n - 1) / 2; totalStep++) {
        f[nxt][sum][totalStep] = inf; 
      }
    }
    for (int sum = 0; sum <= totalZeros; sum++) {
      for (int totalStep = 0; totalStep <= n * (n - 1) / 2; totalStep++) {
        if (f[cur][sum][totalStep] == inf) {
          continue; 
        }
        for (int new_value = 0; new_value + sum <= totalZeros; new_value++) {
          int nextSteps = totalStep + std::abs(new_value + sum - prefixSum[i + 1]);
          if (nextSteps > n * (n - 1) / 2) {
            continue; 
          }    
          updateMin(f[nxt][sum + new_value][nextSteps], f[cur][sum][totalStep] + new_value * new_value); 
        } 
      }  
    }
  }
  int value = inf; 
  for (int steps = 0; steps <= n * (n - 1) / 2; steps++) {
    value = std::min(value, f[sz & 1][totalZeros][steps]);
    std::cout << (totalZeros * totalZeros - value) / 2 << ' ';   
  }
  return 0; 
}