#include <iostream> 
#include <math.h>
#include <string>
int numTest; 
int a[200005];
long long sum[200005];           
int n;
std::string s; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      sum[i] = sum[i - 1] + a[i];  
    }
    std::cin >> s;
    long long ans = 0LL;  
    int l = 0;
    int r = n - 1; 
    while (l <= r) {
      while (l <= r && s[l] == 'R') {
        l++; 
      }
      while (l <= r && s[r] == 'L') {
        r--; 
      }
      if (l <= r) {
        ans += sum[r] - sum[l - 1]; 
        l++;
        r--; 
      }
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}