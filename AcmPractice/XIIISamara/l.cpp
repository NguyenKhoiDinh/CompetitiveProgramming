#include <bits/stdc++.h>

using namespace std;

vector <int> v;
int n;

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  long long ans = 0LL;
  for (int i = 0; i < n; i++) {
    ans += max(v[i] - (i + 1), 0);
  }
  cout << ans;
  return 0;
}