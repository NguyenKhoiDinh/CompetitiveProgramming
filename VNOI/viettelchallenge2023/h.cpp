#include <iostream>
#include <math.h> 
#include <map>
#include <algorithm>
#include <vector>
int n;
int a[5005]; 
long long dp[5005][5005];
std::vector <int> v;
std::vector <int> value;  
int mapValue[5005]; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
    v.push_back(a[i]);
  }
  std::sort(v.begin(), v.end());
  value.push_back(v[0]);
  for (int i = 1; i < (int) v.size(); i++) {
    if (v[i] != v[i - 1]) {
      value.push_back(v[i]); 
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (int) value.size(); j++) {
      if (a[i] == value[j]) {
        mapValue[i] = value[j]; 
        break; 
      }
    }
  } 
  int lim = (int) value.size();
  for (int i = 1; i <= n; i++) {
    for (int h = 0; h < lim; h++) {
      dp[i][h] = -1; 
    }
  } 
  for (int h = 0; h < lim; h++) {
    dp[1][h] = std::abs(value[h] - value[mapValue[1]]);  
  }
  for (int i = 1; i <= 
  return 0; 
}