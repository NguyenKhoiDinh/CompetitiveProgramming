#include <iostream> 
int n;
int x, y; 
int a[1000005];

int main () {
  std::cin >> n;
  std::cin >> x >> y;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  long long ans = -1000000000000007LL; 
  long long sum = 0LL;
  long long secondSum = 1000000000000007LL;
  long long mini = 0LL; 
  int cnt = 0; 
  int l = 1;
  int prevl = 1;  
  int resl, resr; 
  for (int i = 1; i <= n; i++) {
    if (a[i] < x) {
      sum = 0;
      secondSum = 1000000000000007LL;
      mini = 0LL;
      cnt = 0;
      l = i + 1;
      prevl = i + 1;  
    }
    else {
      if (a[i] <= y) {
        secondSum = mini;
        prevl = l;
        cnt++;     
      }
      sum += a[i];
      if (cnt > 0 && ans < sum - secondSum) {
        ans = sum - secondSum;
        resr = i;
        resl = prevl; 
      }
      if (mini > sum) {
        l = i + 1;
        mini = sum; 
      }
    }
  }
  std::cout << ans << std::endl;
  std::cout << resl << ' ' << resr;
  return 0; 
}        