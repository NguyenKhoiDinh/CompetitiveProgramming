#include <bits/stdc++.h>

using namespace std;
const long long inf = 10000000000000000LL;
const int MAX_N = 500005;
long long a[MAX_N];
int n;

int main () {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  long long res;
  long long lo = 0LL, hi = inf;
  while (lo <= hi) {
    long long mid = (lo + hi) >> 1;
    long long sum = mid;
    bool check = true;
    for (int i = 1; i <= n; i++) {
      sum += a[i];
      if (sum < 0) {
        check = false;
        break;
      }
    }
    if (check == true) {
      res = mid;
      hi = mid - 1;
    }
    else {
      lo = mid + 1;
    }
  }
  cout << res;
  return 0;
}