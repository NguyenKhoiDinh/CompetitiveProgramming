#include <iostream> 
int cnt[5]; 
int n; 
int numb[5]; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    cnt[x % 5]++; 
  }
  long long ans = 0LL; 
  for (int r1 = 0; r1 < 5; r1++) {
    for (int r2 = r1; r2 < 5; r2++) {
      for (int r3 = r2; r3 < 5; r3++) {
        if ((r1 + r2 + r3) % 5 == 0) {
          for (int i = 0; i < 5; i++) {
            numb[i] = 0; 
          }  
          numb[r1]++;
          numb[r2]++;
          numb[r3]++;
          long long total = 1LL; 
          for (int r = 0; r < 5; r++) {
            if (numb[r] > 0) {
              if (numb[r] == 1) {
                total *= (long long) cnt[r]; 
              }
              else if (numb[r] == 2) {
                total *= (long long) cnt[r] * (cnt[r] - 1) / 2; 
              }
              else {
                total *= (long long) cnt[r] * (cnt[r] - 1) * (cnt[r] - 2) / 6; 
              }
            }
          }
          ans += total; 
        }
      }
    }
  }
  std::cout << ans;
  return 0; 
}