#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
const int MAX_N = 100005;
int a[MAX_N];
int n;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 2000007;
  sort(a + 1, a + n + 1);
  int l = 1;
  int r = n;
  while (l <= r) {
    ans = min(ans, a[l] + a[r]);
    l++;
    r--;
  }
  cout << ans;
  return 0;
}