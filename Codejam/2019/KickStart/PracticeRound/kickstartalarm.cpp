#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1000000007; 
const int MAX_N = 1000015; 
long long x, y, C, D, E1, E2, F;
int numTest;
int N, K;  
long long A[MAX_N];
long long ways[MAX_N];

long long POW(long long x, long long n) {
  if (n == 0) {
    return 1LL;
  }
  long long tmp = POW(x, n >> 1);
  (tmp *= tmp) %= MOD; 
  if (n & 1) {
    (tmp *= x) %= MOD; 
  }
  return tmp; 
}

void init() {
  ways[1] = K % MOD;
  for (int i = 2; i <= N + 5; i++) {
    ways[i] = ways[i - 1];
    long long value = POW(i, K + 1); 
    value -= i; 
    (value += MOD) %= MOD; 
    (value *= POW(i - 1, MOD - 2)) %= MOD; 
    (ways[i] += value) %= MOD;
  }
}

int main () {
  //freopen("input.txt", "r", stdin); 
  //freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> N >> K >> x >> y >> C >> D >> E1 >> E2 >> F;
    for (int i = 1; i <= N; i++) {
      A[i] = (x + y) % F; 
      long long newx = (C * x + D * y + E1) % F; 
      long long newy = (D * x + C * y + E2) % F;
      x = newx; 
      y = newy; 
    }
    init();
    long long ans = 0LL;
    for (int i = 1; i <= N; i++) {
      long long value = ways[i]; 
      (value *= 1LL * (N - i + 1)) %= MOD; 
      (value *= A[i]) %= MOD; 
      (ans += value) %= MOD;
    }
    cout << ans << endl;
  }
  return 0; 
}