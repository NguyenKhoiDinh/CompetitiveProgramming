#include <bits/stdc++.h> 

using namespace std;
int numTest;
int a[200005]; 
int n; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1); 
    long long ans = a[1];
    long long cur = a[1];
    for (int i = 2; i <= n; i++) {
      ans = max(ans, a[i] - cur); 
      cur += a[i] - cur;
    }
    cout << ans << endl;
  }
  return 0; 
}