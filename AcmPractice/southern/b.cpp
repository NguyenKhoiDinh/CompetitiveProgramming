#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 10000005;
const long long MOD = 1000000007;
long long fact[MAX_N]; 
long long sumFact[MAX_N];
long long totalSumFact[MAX_N]; 
int numTest; 

void init() {
  fact[0] = 1LL;
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = (1LL * fact[i - 1] * i) % MOD;   
  }
  sumFact[0] = 1LL;
  for (int i = 1; i < MAX_N; i++) {
    sumFact[i] = (sumFact[i - 1] + fact[i]) % MOD; 
  }
  totalSumFact[0] = 1LL; 
  for (int i = 1; i < MAX_N; i++) {
    totalSumFact[i] = (totalSumFact[i - 1] + sumFact[i]) % MOD; 
  }
}

int main () {
  init(); 
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << 0 << endl; 
      continue; 
    }
    long long res = fact[n]; 
    res -= (2 * sumFact[n - 1]) % MOD;
    (res += MOD) %= MOD;
    res = (res + 1) % MOD; 
    (res += totalSumFact[n - 2]) %= MOD; 
    cout << res << endl;
  }
  return 0; 
}