#include <iostream>
#include <unordered_map> 
#include <math.h>
#include <stdio.h>
int f[1000005][22]; 
int n, numQueries; 
int a[1000005]; 
long long sum[1000005]; 
std::unordered_map <long long, int> lastPos; 

int main () {
  scanf("%d %d", &n, &numQueries); 
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]); 
    sum[i] = sum[i - 1] + a[i]; 
  }
  lastPos[sum[0]] = 0; 
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= 20; j++) {
      f[i][j] = -1; 
    }  
  }
  f[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    f[i][0] = f[i - 1][0]; 
    if (lastPos.find(sum[i]) != lastPos.end()) {
      f[i][0] = std::max(f[i][0], lastPos[sum[i]] + 1);     
    }
    lastPos[sum[i]] = i; 
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 20; j++) {
      if (f[i][j - 1] != -1) {
        int p = f[i][j - 1]; 
        p--; 
        if (p >= 0 && f[p][j - 1] != -1) {
          p = f[p][j - 1]; 
          f[i][j] = p; 
        }
      }
    }
  }
  for (int query = 1; query <= numQueries; query++) {
    int L, R;
    scanf("%d %d", &L, &R); 
    int p = R;
    int ans = 0; 
    for (int j = 20; j >= 0; j--) {
      if (f[p][j] != -1 && f[p][j] >= L) {
        ans += 1 << j;
        p = f[p][j];
        p--; 
        if (p < L) {
          break; 
        }
      }
    }
    printf("%d\n", ans);
  } 
  return 0; 
}