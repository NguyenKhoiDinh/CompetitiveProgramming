#include <bits/stdc++.h> 

using namespace std;

int main () {
  int test; 
  cin >> test;
  for (int tt = 1; tt <= test; tt++) {
    long long k;
    cin >> k;
    long long sqrtValue = (int) sqrt(k);
    k -= sqrtValue * sqrtValue;
    if (k == 0) {
      cout << sqrtValue << ' ' << 1 << endl;
      continue;
    }
    k += sqrtValue * sqrtValue;
    long long total = sqrtValue * sqrtValue;
    if (k <= total + 1 + sqrtValue) {
      cout << k - total << ' ' << sqrtValue + 1 << endl; 
    }
    else {
      cout << sqrtValue + 1 << ' ' << (sqrtValue + 1) * (sqrtValue + 1) - k + 1 << endl;
    }
  }
  return 0; 
}