#include <iostream> 
#include <math.h>
long long a[405], b[405]; 
long long cost[405][405]; 
long long sum[405][405]; 
int n; 
long long ans = -10000000000007LL; 
long long prefixa[405], prefixb[405]; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    prefixa[i] = prefixa[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
    prefixb[i] = prefixb[i - 1] + b[i]; 
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i <= j) {
        cost[i][j] = prefixa[j] - prefixa[i - 1];
      }
      else {
        cost[i][j] = prefixb[i] - prefixb[j - 1]; 
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + cost[i][j]; 
    }
  }
  long long minValue = 0LL; 
  for (int j = 1; j <= n; j++) {
    for (int y = 1; y <= j; y++) {
      minValue = 0LL;
      for (int i = 1; i <= n; i++) {
        long long value = sum[i][j] - sum[i][j - y];
        if (ans < value - minValue) {
          ans = value - minValue;                  
        }
        if (minValue > value) {
          minValue = value;
        }   
      }  
    }
  }
  std::cout << ans;
  return 0; 
}