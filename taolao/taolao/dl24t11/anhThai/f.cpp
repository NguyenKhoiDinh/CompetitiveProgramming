#include <bits/stdc++.h> 

using namespace std;
long long n, m;
int k; 

int main () {
  ios_base::sync_with_stdio(false);
  for (int testCase = 1; testCase <= 5; testCase++) {
    cin >> n >> m >> k; 
    long long ans = 0LL;
    for (int i = 1; i <= k; i++) {
      long long x, y;
      cin >> x >> y;
      ans ^= (x - 1) ^ (y - 1); 
    }
    cout << (ans > 0 ? "YES" : "NO") << endl;
  }
  return 0; 
}