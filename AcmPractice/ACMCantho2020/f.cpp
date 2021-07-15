#include <iostream>

using namespace std;
int n;
char a[1005];

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    ans += (a[i] == a[i + 1]);
  }
  cout << ans;
  return 0;
}