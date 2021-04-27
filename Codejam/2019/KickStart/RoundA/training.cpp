#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 100005; 
const int inf = 1000000007; 
int numTest; 
int n, P; 
int a[MAX_N];

int main () {
  //freopen("input.txt", "r", stdin); 
  //freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n >> P;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1); 
    int sum = 0LL;
    for (int i = 1; i <= P; i++) {
      sum += a[i]; 
    }
    int left = 1; 
    int ans = P * a[P] - sum;
    for (int i = P + 1; i <= n; i++) {
      sum -= a[left];
      left++;
      sum += a[i]; 
      ans = min(ans, P * a[i] - sum);
    }
    cout << ans << endl;
  }
  return 0; 
}