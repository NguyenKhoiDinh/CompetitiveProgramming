#include <bits/stdc++.h>

using namespace std;
int n, a, b;
int c[100005]; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> a >> b;
    int g = __gcd(a, b);
    for (int i = 1; i <= n; i++) {
      cin >> c[i]; 
      c[i] %= g; 
    }   
    sort(c + 1, c + n + 1); 
    int ans = c[n] - c[1]; 
    int maxValue = -1; 
    for (int i = 1; i < n; i++) {
      maxValue = max(maxValue, c[i + 1] - c[i]); 
    }
    ans = min(ans, g - maxValue); 
    cout << ans << endl;
  }
  return 0; 
}