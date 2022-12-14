#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 100005;
int numTest;
int a[MAX_N];
int n, K;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n >> K;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int low = 1;
    int high = 1000000007;
    int ans = 0;
    while (low <= high) {
      int mid = (low + high) >> 1;
      int numAdd = 0;
      for (int i = 2; i <= n; i++) {
        int diff = a[i] - a[i - 1];
        if (diff <= mid) {
          continue;
        }
        numAdd += diff / mid;
        if (diff % mid == 0) {
          numAdd--;
        }
      }
      if (numAdd <= K) {
        ans = mid;
        high = mid - 1;
      }
      else {
        low = mid + 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}