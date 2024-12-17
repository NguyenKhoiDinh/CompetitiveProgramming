#include <bits/stdc++.h>
using namespace std;
struct point {
  long long x, y, w;
  long long d; 
  bool operator < (const point &other) {
    return (d < other.d); 
  } 
}; 
int n, numQueries; 
point a[500005]; 
long long sum[500005]; 

int main () {
  scanf("%d %d", &n, &numQueries);  
  for (int i = 1; i <= n; i++) {
    scanf("%lld %lld %lld", &a[i].x, &a[i].y, &a[i].w);  
    a[i].d = a[i].x * a[i].x + a[i].y * a[i].y; 
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i].w; 
  }
  for (int query = 1; query <= numQueries; query++) {
    long long r; 
    scanf("%lld", &r);
    r *= r;  
    int lo = 1; 
    int hi = n;
    int pos = -1;
    while (lo <= hi) {
      int mid = (lo + hi) / 2; 
      if (a[mid].d <= r) {
        pos = mid; 
        lo = mid + 1; 
      }
      else {
        hi = mid - 1; 
      }
    } 
    if (pos == -1) {
      printf("0");
    }
    else {
      printf("%lld", sum[pos]); 
    }
    printf("\n"); 
  } 
  return 0; 
}