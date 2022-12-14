#include <bits/stdc++.h>

using namespace std;
map <long long, long long> dp;
long long solve(long long n, int p, int q) {
  map <long long, long long> :: iterator it = dp.find(n);
  if (it != dp.end()) {
    return it->second;
  }
  long long v1 = solve(n / p, p, q);
  long long v2 = solve(n / q, p, q);
  dp[n] = v1 + v2;
  return dp[n];
}

class InfiniteSequence {
  public:
  long long calc(long long n, int p, int q) {
    dp[0] = 1;
    return solve(n, p, q);
  }
};
InfiniteSequence I; 

int main () {
  cout << I.calc(1000000000000,2,3);
  return 0;
}