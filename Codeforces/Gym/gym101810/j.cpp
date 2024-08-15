#include <iostream> 
#include <math.h> 
#include <stdio.h>
int numTest; 
long long a, b, v;
long long lowBit(long long x) {
  return x & -x; 
}

int main () {
  scanf("%d", &numTest);  
  for (int testCase = 1; testCase <= numTest; testCase++) {
    scanf("%lld %lld %lld", &a, &b, &v);  
    int idv = -1; 
    int idb = -1; 
    for (long long i = 0; i <= 63; i++) {
      if ((v & (1LL << i)) > 0) {
        idv = i; 
      }  
      if ((b & (1LL << i)) > 0) {
        idb = i; 
      }
    }
    if (idv > idb) {
      printf("%lld\n", b - a + 1); 
      continue; 
    }
    if (v < a) {
      printf("0\n");
      continue; 
    }
    long long r = v; 
    long long l = 0LL;
    long long ans = 0LL; 
    while (true) {
      long long x = lowBit(~r);
      if (x > v) {
        l = a - 1;   
      }  
      else {
        l = r - x; 
      }
      if (std::min(r, b) >= std::max(l, a - 1)) {
        ans = std::max(ans, std::min(r, b) - std::max(l, a - 1)); 
      }
      r = l;
      if (r < a) {
        break; 
      }
    }
    printf("%lld\n", ans);
  }
  return 0; 
}