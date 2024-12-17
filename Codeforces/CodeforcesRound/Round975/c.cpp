#include <bits/stdc++.h>

using namespace std;
long long a[200005];
long long k, sum = 0LL;
int n;  

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> k;
    sum = 0LL;
    long long maxValue = 0; 
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
      sum += a[i];
      maxValue = max(maxValue, a[i]); 
    }  
    for (int h = n; h >= 1; h--) {
      long long l = sum / h;
      if (sum % h != 0) {
        l++; 
      }
      long long r = (sum + k) / h; 
      if (l > r) {
        continue; 
      }
      if (r >= maxValue) {
        cout << h << endl; 
        break; 
      }
    }
  }
  return 0; 
}