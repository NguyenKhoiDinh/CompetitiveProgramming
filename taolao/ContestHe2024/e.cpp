#include <bits/stdc++.h> 

using namespace std;
int numTest;
int minValue[4005][4005], maxValue[4005][4005];
long long f[4005][4005];
long long sum_left[4005][4005], sum[4005][4005];
int a[4005];  

int main () {
  scanf("%d", &numTest);
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, numQueries; 
    scanf("%d %d", &n, &numQueries); 
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);  
    }
    for (int i = 1; i <= n; i++) {
      minValue[i][i] = a[i];
      maxValue[i][i] = a[i]; 
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        minValue[i][j] = min(minValue[i][j - 1], a[j]); 
        maxValue[i][j] = max(maxValue[i][j - 1], a[j]); 
      }                                                
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i + 2; j <= n; j++) {
        f[i][j] = max((long long) a[i] * a[j] * maxValue[i + 1][j - 1], (long long) a[i] * a[j] * minValue[i + 1][j - 1]); 
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i + 2; j <= n; j++) {
        sum_left[i][j] = sum_left[i][j - 1] + f[i][j]; 
      }
    }
    for (int i = n - 2; i >= 1; i--) {
      for (int j = i + 2; j <= n; j++) {
        sum[i][j] = sum[i + 1][j] + sum_left[i][j]; 
      }
    }           
    for (int query = 1; query <= numQueries; query++) {
      int l, r;
      scanf("%d %d", &l, &r); 
      printf("%lld\n", sum[l][r]); 
    }
  }
  return 0; 
}