#include <bits/stdc++.h>

using namespace std;
int numTest;
const int MAX_N = 100005;
const int MAX_V = 10000000;
int sum[MAX_N];
int a[MAX_N];
int cnt[200 * MAX_N];
int n;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    memset(cnt, 0, sizeof(cnt));
    cout << "Case #" << testCase << ": ";
    cin >> n;
    int mini = 0;
    int maxi = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum[i] = sum[i - 1] + a[i];
      maxi = max(maxi, sum[i]);
      mini = min(mini, sum[i]);
    }
    int diff = maxi - mini;
    cnt[MAX_V] = 1;
    long long ans = 0LL;
    for (int i = 1; i <= n; i++) {
      for (int v = 0; v <= (int) sqrt(diff); v++) {
        int prevSum = sum[i] - v * v;
        ans += cnt[prevSum + MAX_V];
      }
      cnt[sum[i] + MAX_V]++;
    }
    cout << ans << endl;
  }
  return 0;
}