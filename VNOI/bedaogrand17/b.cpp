#include <bits/stdc++.h>
using namespace std;
const long long lim = 1000000000000000000LL;  
int numTest; 
long long n; 
map <long long, pair <int, int> > f; 
void init() {
  for (long long x = 2; x <= 1000000; x++) {
    long long sum = 0LL; 
    long long mul = 1LL;
    int step = 0;  
    while (true) {
      sum += mul;
      if (step > 1 && f.find(sum) == f.end()) {
        f[sum] = make_pair(x, step); 
      }
      if (mul <= lim / x) {
        mul *= x;
        step++;    
      }
      else {
        break; 
      }
    }
  }
}

int main () {
  init(); 
  scanf("%d", &numTest);
  for (int testCase = 1; testCase <= numTest; testCase++) {
    scanf("%lld", &n);
    if (n <= 2) {
      printf("-1\n"); 
      continue; 
    }
    if (f.find(n) != f.end()) {
      printf("%d %d\n", f[n].first, f[n].second);   
    }  
    else { 
      long long delta = n * 4LL - 3;
      if (delta < 0) {
        printf("-1\n");
        continue; 
      }
      long long sqrtDelta = (long long) sqrt(delta);  
      if (sqrtDelta * sqrtDelta == delta && (sqrtDelta - 1) % 2 == 0) {
        long long ans = (sqrtDelta - 1) / 2;
        printf("%lld 2\n", ans);   
      }
      else {
        printf("-1\n");
      } 
    }
  }
  return 0; 
}                  