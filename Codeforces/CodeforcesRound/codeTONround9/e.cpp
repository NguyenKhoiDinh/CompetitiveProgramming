#include <bits/stdc++.h> 

using namespace std;
const long long mod = 998244353LL; 
int numTest; 
int n; 
long long a[1000015]; 
long long b[1000015]; 
void init() {
  b[3] = 0;
  for (int i = 4; i <= 1000005; i++) {
    b[i] = ((long long) i * b[i - 1] + i - 2) % mod; 
  }
  for (int i = 3; i <= 1000004; i++) {
    b[i] = (b[i + 1] - b[i] + mod) % mod; 
  }
  a[1] = 1; 
  a[2] = 2; 
  for (int i = 3; i <= 1000000; i++) {
    // ai - 2.ai-1 + ai-2 = bi
    a[i] = b[i];
    a[i] -= a[i - 2];
    if (a[i] < mod) {
      a[i] += mod;
    }
    (a[i] += (2LL * a[i - 1]) % mod) %= mod; 
  }
}

int main () {
  init(); 
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    cout << a[n - 1] << endl; 
  }
  return 0; 
}