#include <bits/stdc++.h> 

using namespace std;
const long long MOD = 1000000007LL; 
int a[1005]; 
int n; 
long long ans = 1LL; 

int main () {
  cin >> n;
  int numbNeg = 0; 
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] < 0) {
      numbNeg++;
    }
    (ans *= 1LL * abs(a[i])) %= MOD;
  }
  if (numbNeg % 2 == 1) {
    ans = 1LL;
    int pos = -1; 
    int biggest = -1000000007; 
    for (int i = 1; i <= n; i++) {
      if (a[i] < 0) {
        if (biggest < a[i]) {
          pos = i;
          biggest = a[i]; 
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i != pos) {
        (ans *= 1LL * abs(a[i])) %= MOD; 
      }
    }
    cout << ans; 
  }
  else {
    for (int i = 1; i <= n; i++) {
      if (a[i] == 0) {
        ans = 1LL; 
        for (int j = 1; j <= n; j++) {
          if (j != i) {
            (ans *= 1LL * abs(a[j])) %= MOD; 
          }
        }
        cout << ans;
        return 0; 
      }
    }
    cout << ans; 
  }
  return 0; 
}