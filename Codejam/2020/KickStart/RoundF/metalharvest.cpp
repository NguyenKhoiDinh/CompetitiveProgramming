#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 100005; 
int numTest;
pair <int, int> a[MAX_N];
int n, k; 

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i].first >> a[i].second; 
    }
    sort(a + 1, a + n + 1); 
    int last = 0; 
    int ans = 0; 
    for (int i = 1; i <= n; i++) {
      a[i].first = max(a[i].first, last);
      if (a[i].first < a[i].second) {
        int numbRobot = (a[i].second - a[i].first + k - 1) / k; 
        ans += numbRobot;
        last = a[i].first + numbRobot * k;
      }
    }
    cout << ans << endl;
  }
  return 0;
}