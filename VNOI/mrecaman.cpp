#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 500005; 
set <long long> S; 
long long a[MAX_N];
int n; 

int main () {
  a[0] = 0LL;
  S.insert(0);
  for (int i = 1; i <= 500000; i++) {
    long long v = a[i - 1] - i; 
    if (v > 0 && S.find(v) == S.end()) {
      a[i] = v;
      S.insert(v);
    }
    else {
      a[i] = a[i - 1] + i;
      S.insert(a[i]);
    }
  }
  while (true) {
    int n; 
    cin >> n;
    if (n == -1) {
      break; 
    }
    cout << a[n] << endl; 
  }
  return 0; 
}