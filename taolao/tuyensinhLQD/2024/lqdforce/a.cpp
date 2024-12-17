#include <iostream>
#include <fstream>

using namespace std;

const int MAX_N = 100005;
const long long mod = 1000000007;
long long fact[MAX_N], inv_fact[MAX_N]; 
int N, numTest;

long long fastpow(const long long &x, const long long &n) {
  if (n == 0) {
    return 1LL; 
  }
  long long ret = fastpow(x, n / 2); 
  (ret *= ret) %= mod; 
  if (n % 2 == 1) {
    (ret *= x) %= mod; 
  }
  return ret; 
}

void init() {
  fact[0] = 1LL;
  inv_fact[0] = 1LL;
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = (fact[i - 1] * i) % mod; 
    inv_fact[i] = fastpow(fact[i], mod - 2); 
  }
}

int main () {
  init();
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> N;
    long long ret = fact[2 * N]; 
    (ret *= inv_fact[N]) %= mod; 
    (ret *= inv_fact[N]) %= mod; 
    (ret *= fastpow(N + 1, mod - 2)) %= mod; 
    cout << ret << endl; 
  }
  return 0;
}