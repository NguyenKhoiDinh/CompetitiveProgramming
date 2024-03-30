#include <iostream>
int numTest; 
long long fibo[100]; 
long long n;

int main () {
  fibo[1] = 1;
  fibo[2] = 1;
  for (int i = 3; i <= 92; i++) {
    fibo[i] = fibo[i - 1] + fibo[i - 2]; 
  } 
  scanf("%d", &numTest);
  for (int testCase = 1; testCase <= numTest; testCase++) {
    scanf("%lld", &n);                  
    int lo = 1; 
    int hi = 92;
    int ans = 0;
    while (lo <= hi) {
      int mid = (lo + hi) / 2; 
      if (fibo[mid] <= n) {
        ans = mid; 
        lo = mid + 1; 
      }
      else {
        hi = mid - 1; 
      }
    }
    printf("%d\n", ans - 2); 
  }
  return 0; 
}