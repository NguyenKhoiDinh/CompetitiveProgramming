#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 100005; 
const long long inf = 1e15; 
int numTest;
int n;
long long W; 
long long a[MAX_N];  
long long sum[MAX_N];

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n >> W;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
      sum[i] = sum[i - 1] + a[i];
    }
    long long half = W / 2;
    long long ans = inf;
    for (int i = 1; i <= n; i++) {
      int lo = 1;
      int hi = i; 
      int minLeft = -1, maxRight = -1; 
      long long value = 0LL;
      while (lo <= hi) {
        int mid = (lo + hi) >> 1; 
        if (a[mid] >= a[i] - half) {
          minLeft = mid; 
          hi = mid - 1; 
        }
        else {
          lo = mid + 1; 
        }
      }
      if (minLeft != -1) {
        value += 1LL * a[i] * (i - minLeft);
        value -= (sum[i - 1] - sum[minLeft - 1]);
        value += sum[minLeft - 1];
        value += 1LL * (W - a[i]) * (minLeft - 1);
      }
      lo = i; 
      hi = n;
      while (lo <= hi) {
        int mid = (lo + hi) >> 1; 
        if (a[mid] <= a[i] + half) {
          maxRight = mid; 
          lo = mid + 1; 
        }
        else {
          hi = mid - 1; 
        }
      }
      if (maxRight != -1) {
        value += sum[maxRight] - sum[i]; 
        value -= 1LL * a[i] * (maxRight - i);
        value += 1LL * (W + a[i]) * (n - maxRight);
        value -= sum[n] - sum[maxRight];
      }
      ans = min(ans, value);
    }
    cout << ans << endl;
  }
  return 0;
}